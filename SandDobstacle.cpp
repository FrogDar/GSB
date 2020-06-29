#include "SandDobstacle.h"
void SandDobstacle::add(int i)
{
	obstacle.push_back(new Obstacle(i));
}
void SandDobstacle::drawLine()
{
	for (int j = 0; j < obstacle.size(); j++)
	{
		obstacle[j]->draw();
		if (obstacle[j]->x < -200)
		{
			delete obstacle[j];
			obstacle.pop_front();
			j--;
		}
	}
	for (auto i : obstacle)
	{
		if (i->getJudged() == false && i->x < 130)i->onKey(-1);
		i->draw();
	}
}
int SandDobstacle::onKey(int key) {
	int index = -1;
	for (int i = 0; i < obstacle.size() && obstacle[i]->x < 400; i++)
		if (obstacle[i]->getJudged() == false) {
			index = i;
			break;
		}

	if (index == -1)return 0;
	else return obstacle[index]->onKey(key);
}