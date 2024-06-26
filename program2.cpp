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
void display_track(int position1, int position2, int position3)
{
    const int width = 45;
    const int height = 23;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';
    char soullessone_char = 'z';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 0; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 4) // Loop through each 3 column in the current row
        track[1][j] = '|';

    //Left and right tracks - vertical lines
    for (int i = 3; i < height - 3; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
    }

    //Left track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
    }

    //Right track - horizontal lines
    for (int i = 4; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 5] = '+';
        track[i][width - 4] = '-';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 0; j < width - 1; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 4) // Loop through each 3 column of the track
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
        track[height - 14][1] = xwing_char;
        break;
    case 7:
        track[height - 16][1] = xwing_char;
        break;
    case 8:
        track[height - 18][1] = xwing_char;
        break;
    case 9:
        track[height - 20][1] = xwing_char;
        break;
    case 10:
        track[1][1] = xwing_char;
        break;
    case 11:
        track[1][width - 40] = xwing_char;
        break;
    case 12:
        track[1][width - 36] = xwing_char;
        break;
    case 13:
        track[1][width - 32] = xwing_char;
        break;
    case 14:
        track[1][width - 28] = xwing_char;
        break;
    case 15:
        track[1][width - 24] = xwing_char;
        break;
    case 16:
        track[1][width - 20] = xwing_char;
        break;
    case 17:
        track[1][width - 16] = xwing_char;
        break;
    case 18:
        track[1][width - 12] = xwing_char;
        break;
    case 19:
        track[1][width - 8] = xwing_char;
        break;
    case 20:
        track[1][width - 4] = xwing_char;
        break;
    case 21:
        track[height - 20][width - 4] = xwing_char;
        break;
    case 22:
        track[height - 18][width - 4] = xwing_char;
        break;
    case 23:
        track[height - 16][width - 4] = xwing_char;
        break;
    case 24:
        track[height - 14][width - 4] = xwing_char;
        break;
    case 25:
        track[height - 12][width - 4] = xwing_char;
        break;
    case 26:
        track[height - 10][width - 4] = xwing_char;
        break;
    case 27:
        track[height - 8][width - 4] = xwing_char;
        break;
    case 28:
        track[height - 6][width - 4] = xwing_char;
        break;
    case 29:
        track[height - 4][width - 4] = xwing_char;
        break;
    case 30:
        track[height - 2][width - 4] = xwing_char;
        break;
    case 31:
        track[height - 2][width - 8] = xwing_char;
        break;
    case 32:
        track[height - 2][width - 12] = xwing_char;
        break;
    case 33:
        track[height - 2][width - 16] = xwing_char;
        break;
    case 34:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 35:
        track[height - 2][width - 24] = xwing_char;
        break;
    case 36:
        track[height - 2][width - 28] = xwing_char;
        break;
    case 37:
        track[height - 2][width - 32] = xwing_char;
        break;
    case 38:
        track[height - 2][width - 36] = xwing_char;
        break;
    case 39:
        track[height - 2][width - 40] = xwing_char;
        break;
    case 40:
        track[height - 2][1] = xwing_char;
        break;
    //From 41, prevent output display error
    case 41:
        track[height - 2][1] = xwing_char;
        break;
    case 42:
        track[height - 2][1] = xwing_char;
        break;
    case 43:
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
        track[height - 14][2] = tiefighter_char;
        break;
    case 7:
        track[height - 16][2] = tiefighter_char;
        break;
    case 8:
        track[height - 18][2] = tiefighter_char;
        break;
    case 9:
        track[height - 20][2] = tiefighter_char;
        break;
    case 10:
        track[1][2] = tiefighter_char;
        break;
    case 11:
        track[1][width - 39] = tiefighter_char;
        break;
    case 12:
        track[1][width - 35] = tiefighter_char;
        break;
    case 13:
        track[1][width - 31] = tiefighter_char;
        break;
    case 14:
        track[1][width - 27] = tiefighter_char;
        break;
    case 15:
        track[1][width - 23] = tiefighter_char;
        break;
    case 16:
        track[1][width - 19] = tiefighter_char;
        break;
    case 17:
        track[1][width - 15] = tiefighter_char;
        break;
    case 18:
        track[1][width - 11] = tiefighter_char;
        break;
    case 19:
        track[1][width - 7] = tiefighter_char;
        break;
    case 20:
        track[1][width - 3] = tiefighter_char;
        break;
    case 21:
        track[height - 20][width - 3] = tiefighter_char;
        break;
    case 22:
        track[height - 18][width - 3] = tiefighter_char;
        break;
    case 23:
        track[height - 16][width - 3] = tiefighter_char;
        break;
    case 24:
        track[height - 14][width - 3] = tiefighter_char;
        break;
    case 25:
        track[height - 12][width - 3] = tiefighter_char;
        break;
    case 26:
        track[height - 10][width - 3] = tiefighter_char;
        break;
    case 27:
        track[height - 8][width - 3] = tiefighter_char;
        break;
    case 28:
        track[height - 6][width - 3] = tiefighter_char;
        break;
    case 29:
        track[height - 4][width - 3] = tiefighter_char;
        break;
    case 30:
        track[height - 2][width - 3] = tiefighter_char;
        break;
    case 31:
        track[height - 2][width - 7] = tiefighter_char;
        break;
    case 32:
        track[height - 2][width - 11] = tiefighter_char;
        break;
    case 33:
        track[height - 2][width - 15] = tiefighter_char;
        break;
    case 34:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 35:
        track[height - 2][width - 23] = tiefighter_char;
        break;
    case 36:
        track[height - 2][width - 27] = tiefighter_char;
        break;
    case 37:
        track[height - 2][width - 31] = tiefighter_char;
        break;
    case 38:
        track[height - 2][width - 35] = tiefighter_char;
        break;
    case 39:
        track[height - 2][width - 39] = tiefighter_char;
        break;
    case 40:
        track[height - 2][2] = tiefighter_char;
        break;
    //From 41, prevent output display error
    case 41:
        track[height - 2][2] = tiefighter_char;
        break;
    case 42:
        track[height - 2][2] = tiefighter_char;
        break;
    case 43:
        track[height - 2][2] = tiefighter_char;
        break;
    }

    //Assign racer 3 symbol
    switch (position3)
    {
    case 0:
        track[height - 2][3] = soullessone_char;
        break;
    case 1:
        track[height - 4][3] = soullessone_char;
        break;
    case 2:
        track[height - 6][3] = soullessone_char;
        break;
    case 3:
        track[height - 8][3] = soullessone_char;
        break;
    case 4:
        track[height - 10][3] = soullessone_char;
        break;
    case 5:
        track[height - 12][3] = soullessone_char;
        break;
    case 6:
        track[height - 14][3] = soullessone_char;
        break;
    case 7:
        track[height - 16][3] = soullessone_char;
        break;
    case 8:
        track[height - 18][3] = soullessone_char;
        break;
    case 9:
        track[height - 20][3] = soullessone_char;
        break;
    case 10:
        track[1][3] = soullessone_char;
        break;
    case 11:
        track[1][width - 38] = soullessone_char;
        break;
    case 12:
        track[1][width - 34] = soullessone_char;
        break;
    case 13:
        track[1][width - 30] = soullessone_char;
        break;
    case 14:
        track[1][width - 26] = soullessone_char;
        break;
    case 15:
        track[1][width - 22] = soullessone_char;
        break;
    case 16:
        track[1][width - 18] = soullessone_char;
        break;
    case 17:
        track[1][width - 14] = soullessone_char;
        break;
    case 18:
        track[1][width - 10] = soullessone_char;
        break;
    case 19:
        track[1][width - 6] = soullessone_char;
        break;
    case 20:
        track[1][width - 2] = soullessone_char;
        break;
    case 21:
        track[height - 20][width - 2] = soullessone_char;
        break;
    case 22:
        track[height - 18][width - 2] = soullessone_char;
        break;
    case 23:
        track[height - 16][width - 2] = soullessone_char;
        break;
    case 24:
        track[height - 14][width - 2] = soullessone_char;
        break;
    case 25:
        track[height - 12][width - 2] = soullessone_char;
        break;
    case 26:
        track[height - 10][width - 2] = soullessone_char;
        break;
    case 27:
        track[height - 8][width - 2] = soullessone_char;
        break;
    case 28:
        track[height - 6][width - 2] = soullessone_char;
        break;
    case 29:
        track[height - 4][width - 2] = soullessone_char;
        break;
    case 30:
        track[height - 2][width - 2] = soullessone_char;
        break;
    case 31:
        track[height - 2][width - 6] = soullessone_char;
        break;
    case 32:
        track[height - 2][width - 10] = soullessone_char;
        break;
    case 33:
        track[height - 2][width - 14] = soullessone_char;
        break;
    case 34:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 35:
        track[height - 2][width - 22] = soullessone_char;
        break;
    case 36:
        track[height - 2][width - 26] = soullessone_char;
        break;
    case 37:
        track[height - 2][width - 30] = soullessone_char;
        break;
    case 38:
        track[height - 2][width - 34] = soullessone_char;
        break;
    case 39:
        track[height - 2][width - 38] = soullessone_char;
        break;
    case 40:
        track[height - 2][3] = soullessone_char;
        break;
    //From 41, prevent output display error
    case 41:
        track[height - 2][3] = soullessone_char;
        break;
    case 42:
        track[height - 2][3] = soullessone_char;
        break;
    case 43:
        track[height - 2][3] = soullessone_char;
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
    int soullessone_SpeedMin = 3;
    int soullessone_SpeedMax = 6;
    int xwing_position = 0;
    int tiefighter_position = 0;
    int soullessone_position = 0;
    int race_rounds = 0;
    int turn_of_race = 1;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)

    cout << "Enter number of rounds for the race: ";
    cin >> race_rounds;

    for (int round = 1; round <= race_rounds; ++round)
    {
        // Reset positions for each new round
        xwing_position = 0;
        tiefighter_position = 0;
        soullessone_position = 0;
        turn_of_race = 1;

        // Display initial track for each round
        cout << "\nRound " << round << endl;
        display_track(xwing_position, tiefighter_position, soullessone_position);

        while (true)
        {
            // Increment turn of the race
            turn_of_race++;

            // Generate random steps for the racers in each iteration
            int xwing_Steps = generateRandomSteps(xwing_SpeedMin, xwing_SpeedMax);
            int tiefighter_Steps = generateRandomSteps(tiefighter_SpeedMin, tiefighter_SpeedMax);
            int soullessone_Steps = generateRandomSteps(soullessone_SpeedMin, soullessone_SpeedMax);

            // Move each racer forward randomly
            xwing_position += xwing_Steps;
            tiefighter_position += tiefighter_Steps;
            soullessone_position += soullessone_Steps;

            // Display turn of the race
            cout << "Turn " << turn_of_race << endl << endl;

            // Mention number of steps each racer moved
            cout << "X Wing moved " << xwing_Steps << " steps" << endl;
            cout << "Tie Fighter moved " << tiefighter_Steps << " steps" << endl;
            cout << "Soulless One moved " << soullessone_Steps << " steps" << endl;

            // Display updated track
            display_track(xwing_position, tiefighter_position, soullessone_position);

            // Check if any racer has reached the end of the track
            if (xwing_position >= 40 && tiefighter_position >= 40 && soullessone_position >= 40)
            {
                cout << "It's a tie for this round!\n" << endl;
                break; // Exit the loop for this round
            }
            else if (xwing_position >= 40)
            {
                cout << "X Wing wins the race for this round!\n" << endl;
                break; // Exit the loop for this round
            }
            else if (tiefighter_position >= 40)
            {
                cout << "Tie Fighter wins the race for this round!\n" << endl;
                break; // Exit the loop for this round
            }
            else if (soullessone_position >= 40)
            {
                cout << "Soulless One wins the race for this round!\n" << endl;
                break; // Exit the loop for this round
            }

            // Pause before next iteration
            this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
        }
    }

    cout << "Game Over" << endl;
    return 0;
}

