#include "../include/boostServiceFunctions.h"
#ifndef __CINT__ /// needed for rootcint

vector<string> GetColumnFromFile(const string path, const unsigned int position, const string delimiter){

  vector<string> outVec;

  ifstream myfile (path.c_str());
  string line;
  bool notEmpty = false;
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      if (line=="") continue;
      if (line.at(0) == '#') continue;
      
      std::vector<std::string> words;
      boost::split(words, line, boost::is_any_of(delimiter));
      
      if (words.size()>position){
	outVec.push_back(words[position]);
	notEmpty = true;
      }
      else{
	outVec.push_back("");
      }
    }
    myfile.close();
  }
  else cout << endl << "[ERROR]\tUnable to open file in GetColumnFromFile() - file: " << path << endl; 
  if (notEmpty){ 
    return outVec;
  }
  else{
    vector<string> emptyVec;
    return emptyVec;
  }

}

vector<double> GetDoubleColumnFromFile(const string path, const unsigned int position, const string delimiter){
  
  vector<double> outVec;
  vector<string> stringVec = GetColumnFromFile(path, position, delimiter);
  
  for (int i=0; i<stringVec.size(); i++){
    double tmpDouble = atof(stringVec[i].c_str());
    outVec.push_back(tmpDouble);
  }
  
  return outVec;
}


/// parse input arguments
int parseOptionsWithBoost(po::variables_map &vm, int argc, char* argv[], po::options_description &desc){
  
  try 
  {  
    try 
    { 
      po::store(po::parse_command_line(argc, argv, desc),  
                vm); /// can throw 
 
      /** --help option 
       */ 
      if ( vm.count("help")  ) 
      { 
        std::cout << "Available options:" << std::endl 
                  << desc << std::endl; 
        return HELP_CALLED; 
      } 
      
 
      po::notify(vm); /// throws on error, so do after help in case 
                      /// there are any problems 
    } 
    catch(po::error& e) 
    { 
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
      std::cerr << desc << std::endl; 
      return ERROR_IN_COMMAND_LINE; 
    } 
 
    /// application code here // 
    return SUCCESS;
 
  } 
  catch(std::exception& e) 
  { 
    std::cerr << "Unhandled Exception reached the top of main: " 
              << e.what() << ", application will now exit" << std::endl; 
    return ERROR_UNHANDLED_EXCEPTION; 
 
  } 
  
}








#endif
