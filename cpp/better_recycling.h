#pragma once
#include <vector>

class Command;

void better_recycle(std::vector<Command *> &commands);
void parallel_recycle(std::vector<Command *> &commands);
