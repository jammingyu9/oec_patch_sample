#include "ConfigParser.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <exception>

bool ConfigParser::parseConfig()
{
    try {
        std::ifstream file("oec.config")
        std::istringstream issFile;
        
        issFile << file.rdbuf();
        file.close();

        std::string line;
        while (std::getline(issFile, line))
        {
            std::istringstream issLine(line);
            std::string key;

            if (std::getline(issLine, key, '='))
            {
                std::string value;
                if (std::getline(issLine, value)) {
                    if (key == "oec.start_result") {
                        startRes = (value == "true") ? true : false;
                    } else if (key == "oec.task_wrap_up_result") {
                        wrapUpRes = (value == "true") ? true : false;
                    } else if (key == "oec.ready_result") {
                        patchReadyRes = (value == "true") ? true : false;
                    } else if (key == "oec.terminate_result") {
                        terminateRes = (value == "true") ? true : false;
                    }
                }
            }
        }
    } catch (std::exception& exp) {
        std::cerr << "exception while parsing config: " << exp.what() << std::endl; 
        std::terminate();
    }

}