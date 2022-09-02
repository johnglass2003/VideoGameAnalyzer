#include "VideoGame.h"

VideoGame::VideoGame()
{
    this->title = "";
    this->genres = "";
    this->max_players = 0;
    this->review_score = 0;
    this->price = 0;
    this->console = "";
    this->rating = "";
    this->year = 0;
    this->completion = 0;
}

VideoGame::VideoGame(std::string title, std::string genres, int max_players, int review_score, float price,
                     std::string console, std::string rating, int year, float completion)
{
    this->title = title;
    this->genres = genres;
    this->max_players = max_players;
    this->review_score = review_score;
    this->price = price;
    this->console = console;
    this->rating = rating;
    this->year = year;
    this->completion = completion;
}

std::string VideoGame::getTitle()
{
    return title;
}

std::string VideoGame::getGenres()
{
    return genres;
}

int VideoGame::getPlayers() const
{
    return max_players;
}

int VideoGame::getReview() const
{
    return review_score;
}

float VideoGame::getPrice() const
{
    return price;
}

std::string VideoGame::getConsole()
{
    return console;
}

std::string VideoGame::getRating()
{
    return rating;
}

int VideoGame::getYear() const
{
    return year;
}

float VideoGame::getCompletion() const
{
    return completion;
}
