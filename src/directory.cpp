/*
 * directory.cpp
 *
 *  Created on: 02.01.2019
 *      Author: Thomas
 */

#include "directory.h"
#include "file.h"
#include "tinydir.h"
#include <ctime>

Directory::Directory(const std::string& a_path)
{
	time_t t;
	srand((unsigned) time(&t));

    auto lastSlash = a_path.find_last_of("/\\");
    m_directoryPath = a_path.substr(0, lastSlash);
}

std::string Directory::directoryPath() const
{
	return m_directoryPath;
}

std::vector<File> Directory::allContainingFiles()
{
	std::vector<File> files;

	tinydir_dir dir{};
	tinydir_open(&dir, m_directoryPath.c_str());
	while (dir.has_next)
	{
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		if (!file.is_dir)
		{
			files.push_back(File(file.name, this));
		}

		tinydir_next(&dir);
	}
	tinydir_close(&dir);

	return files;
}
