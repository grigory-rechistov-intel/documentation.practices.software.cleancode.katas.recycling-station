#include "recyclingstation.h"
#include "better_recycling.h"
#include "garbage.h"
#include "crusher.h"

#include "commands.h"

#include <gmock/gmock.h>

class MyTest : public ::testing::Test {
};


TEST_F(MyTest, test_recycle)
{
    auto sm = Smelter();
    auto cr = Crusher();
    auto m1 = ScrapMetal(10);
    auto g2 = Glass(3);

    std::vector<Garbage *> load = {&g2, &m1};
    recycle(load, sm, cr);

    EXPECT_EQ (0, 0);

}

TEST_F(MyTest, test_better_recycle)
{
    auto sm = Smelter();
    auto cr = Crusher();
    auto m1 = ScrapMetal(22);
    auto g2 = Glass(44);

    auto gl_cmd = CrushCommand(g2, cr);
    auto mt_cmd = SmeltCommand(m1, sm);

    std::vector<Command *> load = {&gl_cmd, &mt_cmd};
    better_recycle(load);

    EXPECT_EQ (0, 0);

}

TEST_F(MyTest, test_parallel_recycle)
{
    auto sm = Smelter();
    auto cr = Crusher();
    auto m1 = ScrapMetal(66);
    auto g2 = Glass(55);

    auto gl_cmd = CrushCommand(g2, cr);
    auto mt_cmd = SmeltCommand(m1, sm);

    std::vector<Command *> load = {&gl_cmd, &mt_cmd};
    parallel_recycle(load);

    EXPECT_EQ (0, 0);

}

