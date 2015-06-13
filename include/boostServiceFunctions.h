#ifndef boostServiceFunctions_H
#define boostServiceFunctions_H

/// basic stuff:
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>      /// std::ifstream

/// boost
#ifndef __CINT__ /// needed for rootcint
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

/// ROOT stuff
#include <TGraphErrors.h>
#endif

using namespace std;
namespace 
{ 
  const size_t ERROR_IN_COMMAND_LINE = 1; 
  const size_t SUCCESS = 0; 
  const size_t ERROR_UNHANDLED_EXCEPTION = 2; 
  const size_t HELP_CALLED = 3;
  
  namespace po = boost::program_options;
 
} /// namespace  


vector<string> GetColumnFromFile(const string path, const unsigned int position, const string delimiter = "\t");
vector<double> GetDoubleColumnFromFile(const string path, const unsigned int position, const string delimiter = "\t");
// std::map<string,double> ReadMap(const string path, const string delimiter = "\t");

/// restore dumped graph
TGraphErrors* GetDumpedGraph(string inFileName);

int parseOptionsWithBoost(po::variables_map &vm, int argc, char* argv[], po::options_description &desc);

#endif
