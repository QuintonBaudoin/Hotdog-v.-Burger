#include "ScoreBuffer.h"
#include <fstream>
#include "Aie.h"
#include <cstring>




/*
	Designer: Marco
	Creates the functions for the "ScoreBuffer"
*/

int ScoreBuffer::m_nScores = 0;					// Number of scores
ScoreData *ScoreBuffer::m_scores = nullptr;		// Array of scores
const char *ScoreBuffer::m_path = "scores.dat";
ScoreData ScoreBuffer::m_mostRecent;




/*
	Looks for called file and if it exists opens if not it does nothing.
*/
void ScoreBuffer::load()
{
	//Creates a path
	std::fstream fin;
	
	// Opens file to load from
	fin.open(m_path, std::ios_base::binary | std::ios_base::in);

	// checks to see if fin is open.
	if (fin.is_open())
	{
		//if open loads scores
		fin >> m_nScores;
		m_scores = new ScoreData[m_nScores];
		fin.read((char*)m_scores, sizeof(ScoreData)*m_nScores);
	}
	fin.close();
}

//Draw function

void ScoreBuffer::draw(int x, int y)
{
	char c_score[8];
	itoa(m_mostRecent.score, c_score, 10);

	DrawString(m_mostRecent.m_name, x, y);
	DrawString(c_score, x + 200, y);

	//for loop to draw c_scores and m_scores  to screen
	for (int i = 0; i < m_nScores && i < 10; ++i)
	{
		char c_score[8];	
		itoa(m_scores[i].score, c_score, 10);

		DrawString(m_scores[i].m_name, x, y - (i+1) * 40);
		DrawString(c_score, x + 200, y - (i+1) * 40);
	}
}


/*Saves and closes the file if it exists*/



void ScoreBuffer::save()
{
	// creates a path to save from
	std::fstream fout;

	// opens the path
	fout.open(m_path, std::ios_base::binary | std::ios_base::out);

	//checks to see if pis open
	if (fout.is_open())
	{

		//saves to the file 
		fout << m_nScores;
		fout.write((char*)m_scores, sizeof(ScoreData)*m_nScores);
		delete[] m_scores;
		m_scores = nullptr;
	}
	fout.close();
}


/*
	Adds Wins(scores) to the file. and deletes old scores.q
*/
void ScoreBuffer::addScore(ScoreData a_score)
{

	ScoreData *old_scores  = m_scores;
	m_scores = new ScoreData[m_nScores + 1];

	for (int i = 0; i < m_nScores; ++i)
		m_scores[i] = old_scores[i];

	delete[] old_scores;

	m_scores[m_nScores] = a_score;

	m_mostRecent = a_score;

	m_nScores++;
}