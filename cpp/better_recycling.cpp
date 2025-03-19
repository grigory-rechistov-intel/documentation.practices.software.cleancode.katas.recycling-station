#include "better_recycling.h"
#include "commands.h"

#include <algorithm>
#include <execution>


void better_recycle(std::vector<Command *> &commands) {
    for (auto cmd: commands) {
        (*cmd)();
    }
}

void parallel_recycle(std::vector<Command *> &commands) {
    auto doit = [](Command *cmd) { (*cmd)(); };
    std::for_each (std::execution::par,
        commands.begin(), commands.end(), doit);
}
