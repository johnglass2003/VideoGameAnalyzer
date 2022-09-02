#include <iostream>
#include <string>

class VideoGame
{
    std::string title;
    int max_players;
    std::string genres;
    int review_score;
    float price;
    std::string console;
    std::string rating;
    int year;
    float completion;
public:
    VideoGame();
    VideoGame(std::string title, std::string genres, int max_players, int review_score, float price,
              std::string console, std::string rating, int year, float completion);
    std::string getTitle();
    std::string getGenres();
    int getPlayers() const;
    int getReview() const;
    float getPrice() const;
    std::string getConsole();
    std::string getRating();
    int getYear() const;
    float getCompletion() const;
};
