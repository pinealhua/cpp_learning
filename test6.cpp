/*
virtual、override 和多态




*/

#include <iostream>

class Robot
{
public:
    virtual void work()
    {
        std::cout << "Robot working" << std::endl;
    }
};

class SentryRobot : public Robot
{
public:
    void work() override
    {
        std::cout << "Sentry scanning" << std::endl;
    }
};

int main()
{
    SentryRobot sentry;

    Robot* ptr = &sentry;

    ptr->work();

    return 0;
}
