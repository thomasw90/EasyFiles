/*
 * File.h
 *
 *  Created on: 02.01.2019
 *      Author: Thomas
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>

class Directory;

class File
{

public:
	File(const std::string& a_fileName, Directory* a_parentDirectory);

	std::string fileName() const;
	void changeFileNameToRandom(int a_digits = 9);
	std::string suffix() const;
	Directory* parentDirectory();

private:
	std::string m_fileName;
	Directory* m_parentDirectory;
};

#endif /* FILE_H_ */
