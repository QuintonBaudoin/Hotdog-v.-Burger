#pragma once

/*
		Designer: Marco
		Declares functions and variables for making a
		save fore scores (in my program it is used to see last wins.
*/





struct ScoreData // doesn't matter what's in here
{
	int score;
	char m_name[16];	
};

class ScoreBuffer // Mainly static class for global access
{
	static int m_nScores;		// Number of scores
	static ScoreData *m_scores; // Array of scores
	static ScoreData m_mostRecent; // Most Recently added score
	static const char *m_path;
	ScoreBuffer() {}
public:
	static void load();
	static void draw(int x, int y);
	static void save();
	
	static void addScore(ScoreData a_score);
};