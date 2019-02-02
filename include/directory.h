/*
 * directory.h
 *
 *  Created on: 02.01.2019
 *      Author: Thomas
 */

#ifndef INCLUDE_DIRECTORY_H_
#define INCLUDE_DIRECTORY_H_

#include "file.h"
#include <string>
#include <vector>

class Directory
{
public:
	Directory(const std::string& a_path);
	std::string directoryPath() const;
	std::vector<File> allContainingFiles();

private:
	std::string m_directoryPath;
};

#endif /* INCLUDE_DIRECTORY_H_ */
