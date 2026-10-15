#include <iostream>
#include <tchar.h>
#include <locale>

int _tmain(int argc, _TCHAR* argv[])
{
	// Variable initialization
    int direction = 0; // 0: direction unknown, 1: up, -1: down
    unsigned int changes = 0; // Counter for direction changes
    int new_direction = direction; // New direction
    unsigned int prev, current; // Floor numbers where the elevator stopped
    bool b_done = false; // Flag variable for loop exit condition
    // Data input
    std::cout << "Enter the floor numbers where the elevator stopped.\r\n";
    std::cout << "0 - end of data input.\r\n";
    // Read the first floor
    std::cin >> prev;
    b_done = (prev == 0); // Flag variable for loop exit condition
    while (!b_done)
    {
        std::cin >> current; // Enter the remaining floors
        b_done = (current == 0); // Exit loop if 0 is entered
        // If floors are the same, direction doesn't change;
        // simply skip
        if (!b_done && current != prev)
        {
            // Determine the new current direction
            // between prev and current
            new_direction = 1;
            if (current > prev)
            {
                new_direction = -1;
            }
        }
        // If the direction was already known (i.e., not 0)
        // and it does not match the new direction, then a change has occurred
        if (!b_done && direction != 0 && new_direction != direction)
        {
            changes += 1;
        }
        // Update the history for the next step
        direction = new_direction;
        prev = current;
    }
    // Display information on the screen
    std::cout << "Number of times the elevator changed direction: "
    		  << changes << "\r\n";
    // Pause the output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
    return 0;
}
