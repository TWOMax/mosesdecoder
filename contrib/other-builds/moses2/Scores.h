/*
 * Scores.h
 *
 *  Created on: 23 Oct 2015
 *      Author: hieu
 */

#pragma once
#include <iostream>
#include <string>
#include "TypeDef.h"
#include "MemPool.h"

class FeatureFunction;
class System;

class Scores {
	  friend std::ostream& operator<<(std::ostream &, const Scores &);
public:
  Scores(MemPool &pool, size_t numScores);
  Scores(MemPool &pool, size_t numScores, const Scores &origScores);
  virtual ~Scores();

  SCORE GetTotalScore() const
  { return m_total; }

  void CreateFromString(const std::string &str, const FeatureFunction &featureFunction, const System &system);

  void PlusEquals(const std::vector<SCORE> &scores, const FeatureFunction &featureFunction, const System &system);
  void PlusEquals(const Scores &scores, const System &system);
protected:
	SCORE *m_scores;
	SCORE m_total;
};
