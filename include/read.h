#pragma once
#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_exists(char* file_path);
char* read_file_content(char* file_path);

#endif
