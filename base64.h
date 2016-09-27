//
// Created by dilan on 27/09/16.
//

#ifndef MESH_MEM_BASE64_H
#define MESH_MEM_BASE64_H

#include <string>

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

#endif //MESH_MEM_BASE64_H
