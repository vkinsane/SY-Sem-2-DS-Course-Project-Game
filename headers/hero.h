#pragma once
#include "entity.h"
#include "snake.h"
#include "fireball.h"
class Hero : public Entity
{

public:
	Hero(sf::Texture &tex);
	Hero() {}
	~Hero();

	void update(float delta);
	void attack();
	void setVelocity(float x, float y);
	void jump();
	bool checkPlatformCollision(sf::Sprite object);
	int checkPlatformVectorCollision(std::vector<Platform *>);
	void restoreJumps();
	void setJumpSprite();
	//flips the sprite left or right
	void setOrientation();
	void loseHP();
	bool isInvincible();
	bool checkSnakeCollision(Snake object);
	int checkSnakeVectorCollision(std::vector<Snake *> objectList);
	bool checkFireballCollision(Fireball object);
	int checkFireballVectorCollision(std::vector<Fireball *> objectList);

private:
	bool hit;
	int hitTimer;
	bool invincible;
	bool airDodging;
	int ammo;
	int jumps;
};
