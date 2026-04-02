#pragma once
#ifndef WRITE_H
#define WRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_to_file(char* text_content, char* file_path);
int config_BMake(char *source_file,char* output_file,char* flags,int NumOfFlags);
#endif