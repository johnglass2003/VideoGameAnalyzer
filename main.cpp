#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <sstream>
#include "VideoGame.h"
using namespace std::chrono;

void printMenu();
void printGames(std::vector<VideoGame>& games);
void dataFromCSV(const std::string& filepath, std::vector<VideoGame>& games);
void minPlayerGames(std::vector<VideoGame>& games, int min_players);
void genreGames(std::vector<VideoGame>& games, int genre_choice);
void consoleGames(std::vector<VideoGame>& games, int console_choice);
void mergeTitle(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortTitle(std::vector<VideoGame>& v, int first, int end);
void mergePrice(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortPrice(std::vector<VideoGame>& v, int first, int end);
void mergeReview(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortReview(std::vector<VideoGame>& v, int first, int end);
void mergeRating(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortRating(std::vector<VideoGame>& v, int first, int end);
void mergeCompletion(std::vector<VideoGame>& v, int left, int mid, int right);
void mergeSortCompletion(std::vector<VideoGame>& v, int first, int end);
void swap(std::vector<VideoGame>& v,int a,int b);
int PriceSort(std::vector<VideoGame>& v, int low, int high);
int TitleSort(std::vector<VideoGame>& v, int low, int high);
int ReviewSort(std::vector<VideoGame>& v, int low, int high);
int RatingSort(std::vector<VideoGame>& v, int low, int high);
int CompletionSort(std::vector<VideoGame>& v, int low, int high);
void QuickSortPrice(std::vector<VideoGame>& v, int low, int high);
void QuickSortTitle(std::vector<VideoGame>& v, int low, int high);
void QuickSortReview(std::vector<VideoGame>& v, int low, int high);
void QuickSortRating(std::vector<VideoGame>& v, int low, int high);
void QuickSortCompletion(std::vector<VideoGame>& v, int low, int high);


int main()
{
    int option = 0;
    std::vector<VideoGame> games;
    dataFromCSV("video_games.csv", games);
    printMenu();
    std::cin >> option;
    while(option != 4)
    {
        // Option 1; To sort games
        if(option == 1)
        {
            int sort_choice = 0;
            do
            {
                // Prints sort options menu
                std::cout << "Please choose an option to sort the games: " << std::endl;
                std::cout << "1. Used Price\n2. Review\n3. Rating\n4. Average Completion Time\n5. Back" << std::endl;
                std::cin >> sort_choice;

                // Copies the games into 2 different vectors for both the sorting algorithms
                std::vector<VideoGame> tempVect;
                std::vector<VideoGame> tempVect2;
                for (int i=0; i<games.size(); i++){
                    tempVect.push_back(games[i]);
                    tempVect2.push_back(games[i]);
                }

                // If user decides to sort the games by price
                if(sort_choice == 1)
                {
                    // The timer algorithm was obtained from: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ 
                    // This checks the time when the merge sort starts
                    auto start = high_resolution_clock::now();

                    mergeSortPrice(tempVect, 0, (int)tempVect.size()-1);
                    
                    // This checks the time when the merge sort stops
                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start); // This calculates the difference between the stop and start time
                    start = high_resolution_clock::now(); // Start time for quick sort

                    QuickSortPrice(tempVect2,0,(int) tempVect2.size()-1);

                    stop = high_resolution_clock::now(); // Stop time for quick sort
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    printGames(tempVect); // Prints the games
                    // Prints the times taken for the two sorting algorithms
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                // If user decides to sort the games by review
                else if(sort_choice == 2)
                {
                    auto start = high_resolution_clock::now();

                    mergeSortReview(tempVect, 0, (int) tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();

                    QuickSortReview(tempVect2, 0, (int) tempVect2.size()-1);

                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    printGames(tempVect);
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                // If user decides to sort the games by rating
                else if(sort_choice == 3)
                {
                    auto start = high_resolution_clock::now();

                    mergeSortRating(tempVect, 0, (int)tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();

                    QuickSortRating(tempVect2, 0, (int)tempVect2.size()-1);

                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    printGames(tempVect);
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                // If user decides to sort the games by average completion time
                else if(sort_choice == 4)
                {
                    auto start = high_resolution_clock::now();

                    mergeSortCompletion(tempVect, 0, (int) tempVect.size()-1);

                    auto stop = high_resolution_clock::now();
                    auto m_duration = duration_cast<microseconds>(stop - start);
                    start = high_resolution_clock::now();

                    QuickSortCompletion(tempVect2, 0, (int) tempVect2.size()-1);

                    stop = high_resolution_clock::now();
                    auto q_duration = duration_cast<microseconds>(stop - start);
                    printGames(tempVect);
                    std::cout << "Time taken for merge sort: " << m_duration.count() << " microseconds" << std::endl;
                    std::cout << "Time taken for quick sort: " << q_duration.count() << " microseconds" << std::endl;
                }
                // If the user input is invalid
                else if(sort_choice != 5)
                    std::cout << "Please choose a valid option." << std::endl;
            } while (sort_choice > 5 || sort_choice < 1);
        }
        // If user chooses to filter the games
        else if(option == 2)
        {
            int category_choice = 0;
            do
            {
                // Prints the filtering options
                std::cout << "Please choose an option to filter the games: " << std::endl;
                std::cout << "1. Minimum Number of Players\n2. Genre\n3. Console\n4. Back" << std::endl;
                std::cin >> category_choice;
                // If user decides to filter the games based on players
                if(category_choice == 1)
                {
                    // Prints how many players the user wants for the game
                    int players = 0;
                    std::cout << "What is the minimum number of players you would like for this game? ";
                    std::cin >> players;
                    // If it is a valid amount of players for the list of games, then it goes ahead or else error is outputted
                    if(players > 0 && players < 9)
                    {
                        minPlayerGames(games, players);
                        printGames(games);
                    }
                    else
                    {
                        std::cout << "Sorry! No games are available that support that many players." << std::endl;
                    }
                }
                // If user decides to filter the games based on genre
                else if(category_choice == 2)
                {
                    int genre_choice = 0;
                    do
                    {
                        // Prints the list of genres available
                        std::cout << "Choose what genre of games you would like to play: " << std::endl;
                        std::cout << "1. Action\n2. Adventure\n3. Driving/Racing\n4. Role-Play (RPG)\n5. Simulation\n6. Sports\n7. Strategy\n8. Back" << std::endl;
                        std::cin >> genre_choice;
                        // If it is a valid option, then the list is filtered
                        if(genre_choice > 0 && genre_choice < 8)
                        {
                            genreGames(games, genre_choice);
                            printGames(games);
                        }
                        // Invalid input results in error
                        else if(genre_choice < 1 || genre_choice > 8)
                            std::cout << "Please choose a valid option." << std::endl;
                        // If user decides to choose to go back
                        else
                            category_choice = 0;
                    } while(genre_choice < 1 || genre_choice > 8); // Loops until user picks a valid option
                }
                // If user decides to filter the games based on console
                else if(category_choice == 3)
                {
                    int console_choice = 0;
                    do
                    {
                        // Prints list of consoles available
                        std::cout << "Choose what console you would prefer to play: " << std::endl;
                        std::cout << "1. Nintendo DS\n2. Nintendo Wii\n3. PlayStation 3\n4. Sony PSP\n5. Xbox 360\n6. Back" << std::endl;
                        std::cin >> console_choice;
                        // If it is a valid option, then the list is filtered
                        if(console_choice > 0 && console_choice < 6)
                        {
                            consoleGames(games, console_choice);
                            printGames(games);
                        }
                        // If input is invalid, error is outputted
                        else if(console_choice < 1 || console_choice > 6)
                            std::cout << "Please choose a valid option." << std::endl;
                        // If user decides to go back in the menu
                        else
                            category_choice = 0;
                    } while(console_choice < 1 || console_choice > 6); // Loops until user inputs a valid option
                }
                // If input is invalid
                else if(category_choice != 4)
                    std::cout << "Please choose a valid option." << std::endl;
            } while (category_choice > 4 || category_choice < 1); // Loops until user inputs a valid option
        }
        // If user chooses to reset the list of the games
        else if(option == 3)
        {
            dataFromCSV("video_games.csv", games);
            std::cout << "Games have been reset!" << std::endl;
        }
        // If the user input is invalid
        else
            std::cout << "Please choose a valid option." << std::endl;
        printMenu();
        std::cin >> option;
    }
    return 0;
}

void printMenu()
{
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1. Sort Games\n2. Filter Games\n3. Reset Games\n4. Quit" << std::endl;
}

void printGames(std::vector<VideoGame>& games)
{
    if(games.empty())
        std::cout << "Sorry, no such games meet the criteria!" << std::endl;
    // Loops through the list of games and prints its corresponding data
    for(int i = 0; i < games.size(); i++)
    {
        std::cout << i + 1 << ". " << games[i].getTitle() <<std::endl;
        std::cout << "Release Year: " << games[i].getYear() << " Genres: " << games[i].getGenres() << " Console: " << games[i].getConsole()
                  << " Used Price: $" << games[i].getPrice() << " Review Score: " << games[i].getReview() << " Rating: " << games[i].getRating()
                  << " Average Completion Time: " << games[i].getCompletion() << " Maximum Players: " << games[i].getPlayers() << std::endl;
    }
}

void dataFromCSV(const std::string& filepath, std::vector<VideoGame>& games)
{
    std::ifstream inFile(filepath);
    if(inFile.is_open())
    {
        std::string file_line;
        std::getline(inFile, file_line);
        // Loops through all the lines in the file, & for each line collects the data needed for each video game
        while(std::getline(inFile, file_line))
        {
            std::string temp;
            std::string title;
            std::string temp_players;
            int players;
            std::string genres;
            std::string temp_review;
            int review_score;
            std::string temp_price;
            float price;
            std::string console;
            std::string rating;
            std::string temp_year;
            int year;
            std::string temp_completion;
            float completion;
            std::istringstream stream(file_line);
            std::getline(stream, title, '"');
            std::getline(stream, title, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_players, '"');
            std::getline(stream, temp_players, '"');
            players = std::stoi(temp_players);
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, genres, '"');
            std::getline(stream, genres, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_review, '"');
            std::getline(stream, temp_review, '"');
            review_score = std::stoi(temp_review);
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_price, '"');
            std::getline(stream, temp_price, '"');
            price = std::stof(temp_price);
            std::getline(stream, console, '"');
            std::getline(stream, console, '"');
            std::getline(stream, rating, '"');
            std::getline(stream, rating, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp, '"');
            std::getline(stream, temp_year, '"');
            std::getline(stream, temp_year, '"');
            year = std::stoi(temp_year);
            std::getline(stream, temp_completion, '"');
            std::getline(stream, temp_completion, '"');
            completion = std::stof(temp_completion);
            VideoGame v(title, genres, players, review_score, price, console, rating, year, completion);
            games.push_back(v);
        }
    }
}

void minPlayerGames(std::vector<VideoGame>& games, int min_players)
{
    // Loops through the games and finds the games that have a max player limit that doesn't match the min players inputted and erases that game from the vector
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getPlayers() < min_players)
        {
            games.erase(games.begin() + i);
            i--;
        }
    }
}

void genreGames(std::vector<VideoGame>& games, int genre_choice)
{
    // Converts the input into the corresponding genre
    std::string genre;
    if(genre_choice == 1)
        genre = "Action";
    else if(genre_choice == 2)
        genre = "Adventure";
    else if(genre_choice == 3)
        genre = "Driving";
    else if(genre_choice == 4)
        genre = "RPG";
    else if(genre_choice == 5)
        genre = "Simulation";
    else if(genre_choice == 6)
        genre = "Sports";
    else if(genre_choice == 7)
        genre = "Strategy";
    // Loops through the game and finds for games that do not match the inputted genre; Then such games are erased from the vector
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getGenres().find(genre) == std::string::npos)
        {
            games.erase(games.begin() + i);
            i--;
        }
    }
}

void consoleGames(std::vector<VideoGame>& games, int console_choice)
{
    std::string console;
    if(console_choice == 1)
        console = "DS";
    else if(console_choice == 2)
        console = "Wii";
    else if(console_choice == 3)
        console = "PlayStation";
    else if(console_choice == 4)
        console = "PSP";
    else if(console_choice == 5)
        console = "360";
    // Loops through the game and finds for games that do not match the inputted console; Then such games are erased from the vector
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getConsole().find(console) == std::string::npos)
        {
            games.erase(games.begin() + i);
            i--;
        }
    }
}

//NOTE::The Merge Sort and Quick sort algorithms were both based on Aman's psuedocode within his sorting presentation
//He cites the code from here: https://www.onlinegdb.com/ryRlgsGgD & https://www.onlinegdb.com/HJT6FfMlv

void mergeTitle(std::vector<VideoGame>& v, int left, int mid, int right){
    int v1 = left;
    int v2 = mid + 1;

    std::vector<VideoGame> tempV;

    while (v1 <= mid && v2 <= right) {
        if (v[v1].getTitle() <= v[v2].getTitle()) {
            tempV.push_back(v[v1]);
            v1++;
        }
        else {
            tempV.push_back(v[v2]);
            v2++;
        }
    }

    while (v1 <= mid) {
        tempV.push_back(v[v1]);
        v1++;
    }

    while (v2 <= right) {
        tempV.push_back(v[v2]);
        v2++;
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = tempV[i - left];
    }
}

void mergeSortTitle(std::vector<VideoGame>& v, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergeSortTitle(v, first, mid);
        mergeSortTitle(v, mid + 1, end);
        mergeTitle(v, first, mid, end);
    }
}

void mergePrice(std::vector<VideoGame>& v, int left, int mid, int right){
    int v1 = left;
    int v2 = mid + 1;

    std::vector<VideoGame> tempV;

    while (v1 <= mid && v2 <= right) {
        if (v[v1].getPrice() <= v[v2].getPrice()) {
            tempV.push_back(v[v1]);
            v1++;
        }
        else {
            tempV.push_back(v[v2]);
            v2++;
        }
    }

    while (v1 <= mid) {
        tempV.push_back(v[v1]);
        v1++;
    }

    while (v2 <= right) {
        tempV.push_back(v[v2]);
        v2++;
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = tempV[i - left];
    }
}

void mergeSortPrice(std::vector<VideoGame>& v, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergeSortPrice(v, first, mid);
        mergeSortPrice(v, mid + 1, end);
        mergePrice(v, first, mid, end);
    }
}

void mergeReview(std::vector<VideoGame>& v, int left, int mid, int right){
    int v1 = left;
    int v2 = mid + 1;

    std::vector<VideoGame> tempV;

    while (v1 <= mid && v2 <= right) {
        if (v[v1].getReview() <= v[v2].getReview()) {
            tempV.push_back(v[v1]);
            v1++;
        }
        else {
            tempV.push_back(v[v2]);
            v2++;
        }
    }

    while (v1 <= mid) {
        tempV.push_back(v[v1]);
        v1++;
    }

    while (v2 <= right) {
        tempV.push_back(v[v2]);
        v2++;
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = tempV[i - left];
    }
}

void mergeSortReview(std::vector<VideoGame>& v, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergeSortReview(v, first, mid);
        mergeSortReview(v, mid + 1, end);
        mergeReview(v, first, mid, end);
    }
}

void mergeRating(std::vector<VideoGame>& v, int left, int mid, int right){
    int v1 = left;
    int v2 = mid + 1;

    std::vector<VideoGame> tempV;

    while (v1 <= mid && v2 <= right) {
        if (v[v1].getRating() <= v[v2].getRating()) {
            tempV.push_back(v[v1]);
            v1++;
        }
        else {
            tempV.push_back(v[v2]);
            v2++;
        }
    }

    while (v1 <= mid) {
        tempV.push_back(v[v1]);
        v1++;
    }

    while (v2 <= right) {
        tempV.push_back(v[v2]);
        v2++;
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = tempV[i - left];
    }
}

void mergeSortRating(std::vector<VideoGame>& v, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergeSortRating(v, first, mid);
        mergeSortRating(v, mid + 1, end);
        mergeRating(v, first, mid, end);
    }
}

void mergeCompletion(std::vector<VideoGame>& v, int left, int mid, int right){
    int v1 = left;
    int v2 = mid + 1;

    std::vector<VideoGame> tempV;

    while (v1 <= mid && v2 <= right) {
        if (v[v1].getCompletion() <= v[v2].getCompletion()) {
            tempV.push_back(v[v1]);
            v1++;
        }
        else {
            tempV.push_back(v[v2]);
            v2++;
        }
    }

    while (v1 <= mid) {
        tempV.push_back(v[v1]);
        v1++;
    }

    while (v2 <= right) {
        tempV.push_back(v[v2]);
        v2++;
    }

    for (int i = left; i <= right; i++)
    {
        v[i] = tempV[i - left];
    }
}

void mergeSortCompletion(std::vector<VideoGame>& v, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergeSortCompletion(v, first, mid);
        mergeSortCompletion(v, mid + 1, end);
        mergeCompletion(v, first, mid, end);
    }
}

void swap(std::vector<VideoGame>& v,int a,int b){
    VideoGame temp = v.at(a);
    v.at(a)=v.at(b);
    v.at(b)=temp;
}

int RatingSort(std::vector<VideoGame>& v, int low, int high){
    std::string pivot = v.at(low).getRating();
    int up = low;
    int down = high;

    while(up < down){
        for(int j = up; j < high; j++){
            if(v.at(up).getRating() > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(v.at(down).getRating() < pivot){
                break;
            }
            down--;
        }
        if(up<down){
            swap(v,up,down);
        }
    }
    swap(v,low,down);
    return down;
}
int ReviewSort(std::vector<VideoGame>& v, int low, int high){
    int pivot = v.at(low).getReview();
    int up = low;
    int down = high;

    while(up < down){
        for(int j = up; j < high; j++){
            if(v.at(up).getReview() > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(v.at(down).getReview() < pivot){
                break;
            }
            down--;
        }
        if(up<down){
            swap(v,up,down);
        }
    }
    swap(v,low,down);
    return down;
}
int PriceSort(std::vector<VideoGame>& v, int low, int high){
    int pivot = v.at(low).getPrice();
    int up = low;
    int down = high;

    while(up < down){
        for(int j = up; j < high; j++){
            if(v.at(up).getPrice() > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(v.at(down).getPrice() < pivot){
                break;
            }
            down--;
        }
        if(up<down){
            swap(v,up,down);
        }
    }
    swap(v,low,down);
    return down;
}
int TitleSort(std::vector<VideoGame>& v, int low, int high){
    std::string pivot = v.at(low).getTitle();
    int up = low;
    int down = high;

    while(up < down){
        for(int j = up; j < high; j++){
            if(v.at(up).getTitle() > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(v.at(down).getTitle() < pivot){
                break;
            }
            down--;
        }
        if(up<down){
            swap(v,up,down);
        }
    }
    swap(v,low,down);
    return down;
}

int CompletionSort(std::vector<VideoGame>& v, int low, int high){
    int pivot = v.at(low).getCompletion();
    int up = low;
    int down = high;

    while(up < down){
        for(int j = up; j < high; j++){
            if(v.at(up).getCompletion() > pivot){
                break;
            }
            up++;
        }
        for(int j = high; j > low; j--){
            if(v.at(down).getCompletion() < pivot){
                break;
            }
            down--;
        }
        if(up<down){
            swap(v,up,down);
        }
    }
    swap(v,low,down);
    return down;
}

void QuickSortPrice(std::vector<VideoGame>& v, int low, int high){
    if(low < high){
        int pivot = PriceSort(v,low,high);
        QuickSortPrice(v,low,pivot-1);
        QuickSortPrice(v,pivot+1,high);
    }
}
void QuickSortTitle(std::vector<VideoGame>& v, int low, int high){
    if(low < high){
        int pivot = TitleSort(v,low,high);
        QuickSortTitle(v,low,pivot-1);
        QuickSortTitle(v,pivot+1,high);
    }
}
void QuickSortReview(std::vector<VideoGame>& v, int low, int high){
    if(low < high){
        int pivot = ReviewSort(v,low,high);
        QuickSortReview(v,low,pivot-1);
        QuickSortReview(v,pivot+1,high);
    }
}
void QuickSortRating(std::vector<VideoGame>& v, int low, int high){
    if(low < high){
        int pivot = RatingSort(v,low,high);
        QuickSortRating(v,low,pivot-1);
        QuickSortRating(v,pivot+1,high);
    }
}
void QuickSortCompletion(std::vector<VideoGame>& v, int low, int high){
    if(low < high){
        int pivot = CompletionSort(v,low,high);
        QuickSortCompletion(v,low,pivot-1);
        QuickSortCompletion(v,pivot+1,high);
    }
}
