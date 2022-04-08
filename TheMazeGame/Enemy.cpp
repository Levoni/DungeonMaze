#include "Enemy.h"

Enemy::Enemy(int mapSize, int level) : Character(mapSize)
{
   imgName = "default";
   moveMethod = 0;
   pointValue = 20;
}

/*
int Enemy::SeesPlayer(int direction, int distanceRemaining, int curTileX,
                      int curTileY, int heroCurTileXL, int heroCurTileXR, 
                      int heroCurTileYT, int heroCurTileYB, 
                      map<pair<int, int>, Tile*>& tileMap)
{
   if ((curTileX == heroCurTileXL && curTileY == heroCurTileYT) ||
       (curTileX == heroCurTileXL && curTileY == heroCurTileYB) ||
       (curTileX == heroCurTileXR && curTileY == heroCurTileYT) ||
       (curTileX == heroCurTileXR && curTileY == heroCurTileYB))
      return direction;
   else if (distanceRemaining > 0)
      if (direction == 5 && 
          !tileMap[make_pair(curTileX, curTileY)]->HasTopWall())
         return SeesPlayer(5, distanceRemaining - 1, curTileX,
                           curTileY - 1, heroCurTileXL, heroCurTileXR,
                           heroCurTileYT, heroCurTileYB, tileMap);
      else if (direction == 2 && 
               !tileMap[make_pair(curTileX, curTileY)]->HasBottomWall())
         return SeesPlayer(2, distanceRemaining - 1, curTileX,
                           curTileY + 1, heroCurTileXL, heroCurTileXR,
                           heroCurTileYT, heroCurTileYB, tileMap);
      else if (direction == 1 && 
               !tileMap[make_pair(curTileX, curTileY)]->HasLeftWall())
         return SeesPlayer(1, distanceRemaining - 1, curTileX - 1,
                           curTileY, heroCurTileXL, heroCurTileXR,
                           heroCurTileYT, heroCurTileYB, tileMap);
      else if (direction == 3 && 
               !tileMap[make_pair(curTileX, curTileY)]->HasRightWall())
         return SeesPlayer(3, distanceRemaining - 1, curTileX + 1,
                           curTileY, heroCurTileXL, heroCurTileXR, 
                           heroCurTileYT, heroCurTileYB, tileMap);
   return 0;
}
*/

bool Enemy::IsAtDestination()
{
  return location->first >= destination.first - moveDistance
		&& location->first <= destination.first + moveDistance
		&& location->second >= destination.second - moveDistance
		&& location->second <= destination.second + moveDistance;
}