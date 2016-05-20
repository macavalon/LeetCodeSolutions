#ifndef _62_UNIQUE_PATHS
#define _62_UNIQUE_PATHS

#include <queue>
#include <iostream>
#include <vector>

using std::queue;
using std::cout;
using std::endl;
using std::vector;

namespace leetcode {

	class Solution {
public:

    struct coord {
        int x;
        int y;
    };

    struct node {
        coord _coord;
        //coord _predecessor;    
    
    };

    int uniquePaths(int m, int n) {
        queue<node> moves;
        
        //most likely a bfs
        
        //count of unique paths
        
        //what is a unique path
        // where order of nodes traversed is important
        
        //examples
        //3x7
        
        //initiail sample of possible moves
        //0,0  1,0  2,0  3,0  4,0  5,0  6,0  6,1  6,2 (0 down, n-1 right, then m-1 down)
        //0,0  1,0  2,0  3,0  4,0  5,0  5,1  5,2  6,2 (n-2 right, then m-1 down, then 1 right)
        //0,0  0,1  1,1  2,1  3,1  4,1  5,1  6,1  6,2 (1 down, n-1 right, 1 down)
        //0,0  0,1  0,2  1,2  2,2  3,2  4,2  5,2  6,2 (m-1 down, n-1 right, 0 down)
        
        //recursive solution always blow stack..
        // so use a queue of moves
        
        //list<coord> visited
        node next;
        next._coord.x = 0;
        next._coord.y = 0;
        
        moves.push(next);
        
        int pathCount = 0;
        
        while(!moves.empty())
        {
            node current = moves.front();
            moves.pop();
            
            bool moveRight = current._coord.x!=n-1;
            bool moveDown = current._coord.y!=m-1;
            cout << "checking x " << current._coord.x << " y " <<current._coord.y << endl;
            if( moveRight || moveDown)
            {
                //add potential moves
                
                
                //right move
                if(moveRight)
                {
                    node next;
                   // next._predecessor = current;
                    next._coord.x = current._coord.x+1;
                    next._coord.y = current._coord.y;
                    moves.push(next);
                }
                
                // down move
                if(moveDown)
                {
                    node next;
                    //next._predecessor = current;
                    next._coord.x = current._coord.x;
                    next._coord.y = current._coord.y+1;
                    
                    moves.push(next);
                }
            }
            else
            {
                //reached the destination... is a valid path    
                pathCount++;
            }
        }
        //above is too slow due to create of elements
		//quicker way is
		if (m < 1 || n < 1)
        return 0;

		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		return dp[m-1][n-1];
        
        return pathCount;
        
        //moves above would create
        //
        // step 0 start 0,0 
        // step 1 1,0 and 0,1
        // step 2 2,0 2,1 1,1 1,2
        // step 3 3,0
        
        //
        // x by y here is n by m
        //
        // coordinates are
        // xo to x(n-1)
        // y0 to y(m-1)
        
        //start is 0,0
        // end is n-1,m-1
        
        //move is only down or right (can't go backwards/upwards)
        // i.e. x++ and y++

    }
};

};

#endif