// Copyright (c) 2022 wm8
#include "Utils.h"
#include "SHA256.h"
void Terminate(int exit_code)
{
  Program::instance()->SaveData();

  BOOST_LOG_TRIVIAL(info) << "exit code: " << exit_code;
  Program::instance()->terminated= true;
  BOOST_LOG_TRIVIAL(info) << "terminated: "
                          <<  Program::instance()->terminated;
  delete Program::instance();
}
int ParseArgs(Program* _p, int argc, char **argv)
{
  po::options_description desc("Allowed options");
  desc.add_options()
      ("M", po::value<unsigned int>(), "кол-во потоков")
          ("f", po::value<std::string>(), "имя файла")
      ;
  po::variables_map map;
  try {
    po::store(po::parse_command_line(argc, argv, desc), map);
    po::notify(map);
  }catch(exception& e) {
    BOOST_LOG_TRIVIAL(fatal) << "error: " << e.what();
    return EXIT_FAILURE;
  }
  if(!map.count("f")) {
    BOOST_LOG_TRIVIAL(fatal) << "Not enough args";
    return EXIT_FAILURE;
  }
  _p->file_name = map["f"].as<std::string>();
  if(map.count("M"))
    _p->M=map["M"].as<unsigned int>();
  else
    _p->M=std::thread::hardware_concurrency();
  return EXIT_SUCCESS;
}
void InitLogging(std::string logfile)
{
  boost::filesystem::absolute("");
  logging::add_file_log(logfile, logging::keywords::auto_flush = true );
  logging::add_console_log(std::cout);
}
bool checkSHA(string sha) {
  int N=4;
  char c='0';
  size_t len = sha.length();
  for(int i=0; i != N; i++)
    if(sha[len-i-1] != c)
      return false;
  return true;
}
void task(unsigned int thread_id)
{
  auto p = Program::instance();
  SHA256 sha256;
  Randomizer rand(thread_id);
  auto _p = Program::instance();
  while (!p->terminated) {
    auto word = rand.get();
    string hash = sha256(word);
    BOOST_LOG_TRIVIAL(trace) << "thread "<< thread_id<<": "<< word<<" - "<< hash;
    if(checkSHA(hash))
    {
      const auto p1 = std::chrono::system_clock::now();
        json j;
        j["timestamp"] = std::chrono::duration_cast<std::chrono::seconds>(
                           p1.time_since_epoch()).count();
        j["hash"] = hash;
        j["data"] = word;
        _p->shas.push_back(j);
        BOOST_LOG_TRIVIAL(info) << "thread "<< thread_id
                                << " FOUND! word: " << word << " hash: " << hash;
    }
  }
}
