/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2016 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                              SOFA :: Framework                              *
*                                                                             *
* Authors: The SOFA Team (see Authors.txt)                                    *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/

#include <sofa/helper/system/config.h>

#include "FileAccess.h"

#include <iostream>

namespace sofa
{

namespace helper
{

namespace io
{

FileAccess::FileAccess() : BaseFileAccess(),
    myFile()
{

}

FileAccess::~FileAccess()
{
    close();
}

bool FileAccess::open(const std::string& filename, std::ios_base::openmode openMode)
{
    myFile.open(filename, openMode);
    return myFile.is_open();
}

void FileAccess::close()
{
    myFile.close();
}

std::streambuf* FileAccess::streambuf() const
{
    return myFile.rdbuf();
}

std::string FileAccess::readAll()
{
    std::string data;

    myFile.seekg(0, std::ios::end);
    data.reserve(myFile.tellg());
    myFile.seekg(0, std::ios::beg);

    data.assign(std::istreambuf_iterator<char>(myFile),
                std::istreambuf_iterator<char>());

    return data;
}

} // namespace io

} // namespace helper

} // namespace sofa

