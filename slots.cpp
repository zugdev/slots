#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class PayoutRange
{
public:
    int lower;
    int upper;
    double multiplier;

    PayoutRange(int l, int u, double m) : lower(l), upper(u), multiplier(m) {}
};

class SlotsGame
{
private:
    std::vector<PayoutRange> ranges;

public:
    SlotsGame()
    {
        ranges.emplace_back(0, 9, 20.0);
        ranges.emplace_back(10, 109, 1.5);
        ranges.emplace_back(110, 1110, 1.0);
        ranges.emplace_back(1111, 9999, 0.5);
    }

    double getMultiplier(int randomValue) const
    {
        for (const auto &range : ranges)
        {
            if (randomValue >= range.lower && randomValue <= range.upper)
            {
                return range.multiplier;
            }
        }
        return 0.0; // Should not happen if ranges cover all possibilities
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

    SlotsGame game;

    // Simulate 10 rounds of the slots game
    for (int i = 0; i < 10; i++)
    {
        int randomValue = rand() % 10000; // Generate random number between 0 and 9999
        double multiplier = game.getMultiplier(randomValue);
        std::cout << "Random Value: " << randomValue << ", Multiplier: " << multiplier << std::endl;
    }

    return 0;
}
