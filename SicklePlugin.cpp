#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SicklePlugin.h"

void SicklePlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void SicklePlugin::run() {
   
}

void SicklePlugin::output(std::string file) {
	//./sickle se -f /biorg/data/RNA/UMiami/small/S12_R1.fastq -t sanger -o S12_R1.trimmed.fastq -q 37
	std::string command = "sickle se -f "+std::string(PluginManager::prefix())+"/"+parameters["fastq"];
	command += " -t "+parameters["type"];
	command += " -q "+parameters["quality"];
        command += " -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<SicklePlugin> SicklePluginProxy = PluginProxy<SicklePlugin>("Sickle", PluginManager::getInstance());
