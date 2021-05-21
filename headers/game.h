#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "screen.h"
#include "hero.h"
#include "fireball.h"
#include "directedGraph.h"

//menu class inherits the screen class and overrids the Run function
class Game : public Screen
{

public:
	Game(float width, float height, sf::Texture &masterTexture);
	~Game();

	int Run(sf::RenderWindow &window, float delta);
	int gameoverflag = 0;
	void setBackground();
	void createPlatformVector();
	void updateView();
	void updateView2();
	void updateBackground();

	void assignNeighbors();
	void verifyPlatforms();

	Platform *createPlatform(int num);

	Snake createSnake();
	void createSnakeVector();

	void createFireball();

	void resetGame();
	void gameOverSetup();

private:
	int timer;
	int fps;
	int highscore = 0;
	float windowHeight;
	float windowWidth;

	sf::View view;

	sf::Texture *masterTexture;
	sf::Texture *controlTexture;
	sf::Sprite ground;
	sf::Sprite platform;
	sf::Sprite background;

	float maxHeight;
	int fireballTimer;
	bool backgroundChanged;

	sf::Font font;
	sf::Text score;
	sf::Text highscoretext;
	sf::Text hitpointstext;
	sf::Text gameovertext;
	//music is declared as a pointer as a workaround to not being able to use classes
	//that inherit sf::nonCopyable
	sf::Music *music;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	Hero player;
	std::vector<Platform *> platforms;
	std::vector<Entity *> snakes;
	std::vector<Entity *> fireballs;
	Snake snake;

	directedGraph<int> platformGraph;
};
