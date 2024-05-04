#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// Function to generate random steps within a range for each racer
int generateRandomSteps(int minSteps, int maxSteps) {
    return rand() % (maxSteps - minSteps + 1) + minSteps;
}

void display_track(int position1, int position2)
{
    const int width = 31;
    const int height = 15;

    char track[height][width];
    
    char racer1_char = 'x';
    char racer2_char = 'y';

    //Initialize all to spaces
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2)
    {
        for (int j = 0; j < width - 1; j = j + 3)
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 3)
        track[1][j] = '|';

    //Left and right tracks - vertical lines
    for (int i = 3; i < height - 3; i = i + 2)
    {
        track[i][0] = '|';
        track[i][3] = '|';
        track[i][width - 4] = '|';
        track[i][width - 1] = '|';
    }

    //Left track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2)
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '+';
    }

    //Right track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2)
    {
        track[i][width - 4] = '+';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2)
    {
        for (int j = 0; j < width - 1; j = j + 3)
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 3)
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    case 0:
        track[height - 2][1] = racer1_char;
        break;
    case 1:
        track[height - 4][1] = racer1_char;
        break;
    case 2:
        track[height - 6][1] = racer1_char;
        break;
    case 3:
        track[height - 8][1] = racer1_char;
        break;
    case 4:
        track[height - 10][1] = racer1_char;
        break;
    case 5:
        track[height - 12][1] = racer1_char;
        break;
    case 6:
        track[1][1] = racer1_char;
        break;
    case 7:
        track[1][width - 27] = racer1_char;
        break;
    case 8:
        track[1][width - 24] = racer1_char;
        break;
    case 9:
        track[1][width - 21] = racer1_char;
        break;
    case 10:
        track[1][width - 18] = racer1_char;
        break;
    case 11:
        track[1][width - 15] = racer1_char;
        break;
    case 12:
        track[1][width - 12] = racer1_char;
        break;
    case 13:
        track[1][width - 9] = racer1_char;
        break;
    case 14:
        track[1][width - 6] = racer1_char;
        break;
    case 15:
        track[1][width - 3] = racer1_char;
        break;
    case 16:
        track[height - 12][width - 3] = racer1_char;
        break;
    case 17:
        track[height - 10][width - 3] = racer1_char;
        break;
    case 18:
        track[height - 8][width - 3] = racer1_char;
        break;
    case 19:
        track[height - 6][width - 3] = racer1_char;
        break;
    case 20:
        track[height - 4][width - 3] = racer1_char;
        break;
    case 21:
        track[height - 2][width - 3] = racer1_char;
        break;
    case 22:
        track[height - 2][width - 6] = racer1_char;
        break;
    case 23:
        track[height - 2][width - 9] = racer1_char;
        break;
    case 24:
        track[height - 2][width - 12] = racer1_char;
        break;
    case 25:
        track[height - 2][width - 15] = racer1_char;
        break;
    case 26:
        track[height - 2][width - 18] = racer1_char;
        break;
    case 27:
        track[height - 2][width - 21] = racer1_char;
        break;
    case 28:
        track[height - 2][width - 24] = racer1_char;
        break;
    case 29:
        track[height - 2][width - 27] = racer1_char;
        break;
    case 30:
        track[height - 2][1] = racer1_char;
        break;
    case 31:
        track[height - 2][1] = racer1_char;
        break;
    case 32:
        track[height - 2][1] = racer1_char;
        break;
    case 33:
        track[height - 2][1] = racer1_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    case 0:
        track[height - 2][2] = racer2_char;
        break;
    case 1:
        track[height - 4][2] = racer2_char;
        break;
    case 2:
        track[height - 6][2] = racer2_char;
        break;
    case 3:
        track[height - 8][2] = racer2_char;
        break;
    case 4:
        track[height - 10][2] = racer2_char;
        break;
    case 5:
        track[height - 12][2] = racer2_char;
        break;
    case 6:
        track[1][2] = racer2_char;
        break;
    case 7:
        track[1][width - 26] = racer2_char;
        break;
    case 8:
        track[1][width - 23] = racer2_char;
        break;
    case 9:
        track[1][width - 20] = racer2_char;
        break;
    case 10:
        track[1][width - 17] = racer2_char;
        break;
    case 11:
        track[1][width - 14] = racer2_char;
        break;
    case 12:
        track[1][width - 11] = racer2_char;
        break;
    case 13:
        track[1][width - 8] = racer2_char;
        break;
    case 14:
        track[1][width - 5] = racer2_char;
        break;
    case 15:
        track[1][width - 2] = racer2_char;
        break;
    case 16:
        track[height - 12][width - 2] = racer2_char;
        break;
    case 17:
        track[height - 10][width - 2] = racer2_char;
        break;
    case 18:
        track[height - 8][width - 2] = racer2_char;
        break;
    case 19:
        track[height - 6][width - 2] = racer2_char;
        break;
    case 20:
        track[height - 4][width - 2] = racer2_char;
        break;
    case 21:
        track[height - 2][width - 2] = racer2_char;
        break;
    case 22:
        track[height - 2][width - 5] = racer2_char;
        break;
    case 23:
        track[height - 2][width - 8] = racer2_char;
        break;
    case 24:
        track[height - 2][width - 11] = racer2_char;
        break;
    case 25:
        track[height - 2][width - 14] = racer2_char;
        break;
    case 26:
        track[height - 2][width - 17] = racer2_char;
        break;
    case 27:
        track[height - 2][width - 20] = racer2_char;
        break;
    case 28:
        track[height - 2][width - 23] = racer2_char;
        break;
    case 29:
        track[height - 2][width - 26] = racer2_char;
        break;
    case 30:
        track[height - 2][width - 29] = racer2_char;
        break;
    case 31:
        track[height - 2][width - 29] = racer2_char;
        break;
    case 32:
        track[height - 2][width - 29] = racer2_char;
        break;
    case 33:
        track[height - 2][width - 29] = racer2_char;
        break;
    case 34:
        track[height - 2][width - 29] = racer2_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int racer1_SpeedMin = 2;
    int racer1_SpeedMax = 4;
    int racer2_SpeedMin = 1;
    int racer2_SpeedMax = 5;
    int racer1_position = 0;
    int racer2_position = 0;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)
    
    // Display initial track
        display_track(racer1_position, racer2_position);

    while (true)
    {
        // Generate random steps for the racers in each iteration
        int racer1_Steps = generateRandomSteps(racer1_SpeedMin, racer1_SpeedMax);
        int racer2_Steps = generateRandomSteps(racer2_SpeedMin, racer2_SpeedMax);

        // Make each racer move forward randomly
        racer1_position += racer1_Steps;
        racer2_position += racer2_Steps;

        display_track(racer1_position, racer2_position);

        // Check if any racer has reached the end of the track
        if (racer1_position >= 30)
        {
            cout << "X Wing wins the race!" << endl;
            break; // Exit the loop
        }
        else if (racer2_position >= 30)
        {
            cout << "Tie Fighter wins the race!" << endl;
            break; // Exit the loop
        }
        // Pause before next iteration
        this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
    }
    return 0;
}
