#include <iostream>
#include <ctime> //for generate random number
#include <chrono> //for pause between iteration
#include <thread> //for pause function
using namespace std;
using namespace std::chrono;

// Function to generate random steps within a range for each racer
int generateRandomSteps(int minSteps, int maxSteps) {
    return rand() % (maxSteps - minSteps + 1) + minSteps;
}

// Function to display track and update racer's position
void display_track(int position1, int position2)
{
    const int width = 31;
    const int height = 15;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 0; j < width - 1; j = j + 3) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 3) // Loop through each 3 column in the current row
        track[1][j] = '|';

    //Left and right tracks - vertical lines
    for (int i = 3; i < height - 3; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][3] = '|';
        track[i][width - 4] = '|';
        track[i][width - 1] = '|';
    }

    //Left track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '+';
    }

    //Right track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 4] = '+';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 0; j < width - 1; j = j + 3) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 3) // Loop through each 3 column of the track
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    case 0:
        track[height - 2][1] = xwing_char;
        break;
    case 1:
        track[height - 4][1] = xwing_char;
        break;
    case 2:
        track[height - 6][1] = xwing_char;
        break;
    case 3:
        track[height - 8][1] = xwing_char;
        break;
    case 4:
        track[height - 10][1] = xwing_char;
        break;
    case 5:
        track[height - 12][1] = xwing_char;
        break;
    case 6:
        track[1][1] = xwing_char;
        break;
    case 7:
        track[1][width - 27] = xwing_char;
        break;
    case 8:
        track[1][width - 24] = xwing_char;
        break;
    case 9:
        track[1][width - 21] = xwing_char;
        
        break;
    case 10:
        track[1][width - 18] = xwing_char;
        break;
    case 11:
        track[1][width - 15] = xwing_char;
        break;
    case 12:
        track[1][width - 12] = xwing_char;
        break;
    case 13:
        track[1][width - 9] = xwing_char;
        break;
    case 14:
        track[1][width - 6] = xwing_char;
        break;
    case 15:
        track[1][width - 3] = xwing_char;
        break;
    case 16:
        track[height - 12][width - 3] = xwing_char;
        break;
    case 17:
        track[height - 10][width - 3] = xwing_char;
        break;
    case 18:
        track[height - 8][width - 3] = xwing_char;
        break;
    case 19:
        track[height - 6][width - 3] = xwing_char;
        break;
    case 20:
        track[height - 4][width - 3] = xwing_char;
        break;
    case 21:
        track[height - 2][width - 3] = xwing_char;
        break;
    case 22:
        track[height - 2][width - 6] = xwing_char;
        break;
    case 23:
        track[height - 2][width - 9] = xwing_char;
        break;
    case 24:
        track[height - 2][width - 12] = xwing_char;
        break;
    case 25:
        track[height - 2][width - 15] = xwing_char;
        break;
    case 26:
        track[height - 2][width - 18] = xwing_char;
        break;
    case 27:
        track[height - 2][width - 21] = xwing_char;
        break;
    case 28:
        track[height - 2][width - 24] = xwing_char;
        break;
    case 29:
        track[height - 2][width - 27] = xwing_char;
        break;
    case 30:
        track[height - 2][1] = xwing_char;
        break;
    //From 31, prevent output display error
    case 31:
        track[height - 2][1] = xwing_char;
        break;
    case 32:
        track[height - 2][1] = xwing_char;
        break;
    case 33:
        track[height - 2][1] = xwing_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    case 0:
        track[height - 2][2] = tiefighter_char;
        break;
    case 1:
        track[height - 4][2] = tiefighter_char;
        break;
    case 2:
        track[height - 6][2] = tiefighter_char;
        break;
    case 3:
        track[height - 8][2] = tiefighter_char;
        break;
    case 4:
        track[height - 10][2] = tiefighter_char;
        break;
    case 5:
        track[height - 12][2] = tiefighter_char;
        break;
    case 6:
        track[1][2] = tiefighter_char;
        break;
    case 7:
        track[1][width - 26] = tiefighter_char;
        break;
    case 8:
        track[1][width - 23] = tiefighter_char;
        break;
    case 9:
        track[1][width - 20] = tiefighter_char;
        break;
    case 10:
        track[1][width - 17] = tiefighter_char;
        break;
    case 11:
        track[1][width - 14] = tiefighter_char;
        break;
    case 12:
        track[1][width - 11] = tiefighter_char;
        break;
    case 13:
        track[1][width - 8] = tiefighter_char;
        break;
    case 14:
        track[1][width - 5] = tiefighter_char;
        break;
    case 15:
        track[1][width - 2] = tiefighter_char;
        break;
    case 16:
        track[height - 12][width - 2] = tiefighter_char;
        break;
    case 17:
        track[height - 10][width - 2] = tiefighter_char;
        break;
    case 18:
        track[height - 8][width - 2] = tiefighter_char;
        break;
    case 19:
        track[height - 6][width - 2] = tiefighter_char;
        break;
    case 20:
        track[height - 4][width - 2] = tiefighter_char;
        break;
    case 21:
        track[height - 2][width - 2] = tiefighter_char;
        break;
    case 22:
        track[height - 2][width - 5] = tiefighter_char;
        break;
    case 23:
        track[height - 2][width - 8] = tiefighter_char;
        break;
    case 24:
        track[height - 2][width - 11] = tiefighter_char;
        break;
    case 25:
        track[height - 2][width - 14] = tiefighter_char;
        break;
    case 26:
        track[height - 2][width - 17] = tiefighter_char;
        break;
    case 27:
        track[height - 2][width - 20] = tiefighter_char;
        break;
    case 28:
        track[height - 2][width - 23] = tiefighter_char;
        break;
    case 29:
        track[height - 2][width - 26] = tiefighter_char;
        break;
    case 30:
        track[height - 2][width - 29] = tiefighter_char;
        break;
    //From 31, prevent output display error
    case 31:
        track[height - 2][width - 29] = tiefighter_char;
        break;
    case 32:
        track[height - 2][width - 29] = tiefighter_char;
        break;
    case 33:
        track[height - 2][width - 29] = tiefighter_char;
        break;
    case 34:
        track[height - 2][width - 29] = tiefighter_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++) // Loop through each row of the track
    {
        for (int j = 0; j < width; j++) // Loop through each column of the track
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(0)); // Seed for random number generation
    int xwing_SpeedMin = 2;
    int xwing_SpeedMax = 4;
    int tiefighter_SpeedMin = 1;
    int tiefighter_SpeedMax = 5;
    int xwing_position = 0;
    int tiefighter_position = 0;
    int round_of_race = 1;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)

    // Display initial track
        cout << "Round " << round_of_race << endl; // Mention round of the race
        cout << endl;
        display_track(xwing_position, tiefighter_position);

    while (true)
    {
        // Display round of the race
        round_of_race = round_of_race + 1;
        cout << "Round " << round_of_race << endl;
        cout << endl;
        

        // Generate random steps for the racers in each iteration
        int xwing_Steps = generateRandomSteps(xwing_SpeedMin, xwing_SpeedMax);
        int tiefighter_Steps = generateRandomSteps(tiefighter_SpeedMin, tiefighter_SpeedMax);

        // Mention round of the race
        cout << "X Wing moved " << xwing_Steps << " steps" << endl;
        cout << "Tie Fighter moved " << tiefighter_Steps << " steps" << endl;

        // Make each racer move forward randomly
        xwing_position = xwing_position + xwing_Steps;
        tiefighter_position = tiefighter_position + tiefighter_Steps;

        display_track(xwing_position, tiefighter_position);


        // Check if any racer has reached the end of the track
        if (xwing_position >= 30 && tiefighter_position >= 30)
        {
            cout << "It's a tie!" << endl;
            break; // Exit the loop
        }
        else if (xwing_position >= 30)
        {
            cout << "X Wing wins the race!" << endl;
            break; // Exit the loop
        }
        else if (tiefighter_position >= 30)
        {
            cout << "Tie Fighter wins the race!" << endl;
            break; // Exit the loop
        }

        // Pause before next iteration
        this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
    }
    return 0;
}
