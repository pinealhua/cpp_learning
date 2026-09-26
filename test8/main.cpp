#include "Robot.hpp"

int main()
{
    Robot robot(3.0);

    robot.printStatus();

    robot.stop();

    robot.printStatus();

    return 0;
}