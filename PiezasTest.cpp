/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, clearBoard)
{
  Piezas temp;
  temp.dropPiece(0);
  temp.reset();
  ASSERT_EQ(temp.pieceAt(0,0), Blank);
}

TEST(PiezasTest, dropEmpty)
{
	Piezas temp;
  temp.dropPiece(0);
  ASSERT_EQ(temp.pieceAt(0,0), X);
}

TEST(PiezasTest, dropTillSwap)
{
	Piezas temp;
  temp.dropPiece(0);
  temp.dropPiece(0);
  ASSERT_EQ(temp.pieceAt(0,1), O);
}

TEST(PiezasTest, dropTillBlank)
{
	Piezas temp;
  temp.dropPiece(0);
  temp.dropPiece(0);
  temp.dropPiece(0);
  ASSERT_EQ(temp.dropPiece(0), Blank);
}

TEST(PiezasTest, dropOutOfBounds)
{
	Piezas temp;
  ASSERT_EQ(temp.dropPiece(-1), Invalid);
}

TEST(PiezasTest, getPieceInBounds)
{
	Piezas temp;
  temp.dropPiece(0);
  temp.dropPiece(0);
  temp.dropPiece(0);
  ASSERT_EQ(temp.pieceAt(0,2), X);
}

TEST(PiezasTest, getPieceOutOfBounds)
{
	Piezas temp;
  ASSERT_EQ(temp.pieceAt(-1,0), Invalid);
}

TEST(PiezasTest, stateXWins)
{
	Piezas temp;
  //      X                O
  temp.dropPiece(0);temp.dropPiece(0);
  temp.dropPiece(1);temp.dropPiece(0);
  temp.dropPiece(2);temp.dropPiece(2);
  temp.dropPiece(3);temp.dropPiece(3);
  temp.dropPiece(1);temp.dropPiece(1);
  temp.dropPiece(2);temp.dropPiece(3);
  ASSERT_EQ(temp.gameState(), X);
}

TEST(PiezasTest, stateOWins)
{
	Piezas temp;
  //      X                O
  temp.dropPiece(3);temp.dropPiece(0);
  temp.dropPiece(3);temp.dropPiece(1);
  temp.dropPiece(0);temp.dropPiece(2);
  temp.dropPiece(0);temp.dropPiece(3);
  temp.dropPiece(1);temp.dropPiece(2);
  temp.dropPiece(1);temp.dropPiece(2);
  ASSERT_EQ(temp.gameState(), O);
}

TEST(PiezasTest, stateTie)
{
	Piezas temp;
  //      X                O
  temp.dropPiece(0);temp.dropPiece(1);
  temp.dropPiece(2);temp.dropPiece(3);
  temp.dropPiece(0);temp.dropPiece(1);
  temp.dropPiece(2);temp.dropPiece(3);
  temp.dropPiece(0);temp.dropPiece(1);
  temp.dropPiece(2);temp.dropPiece(3);
  ASSERT_EQ(temp.gameState(), Blank);
}

TEST(PiezasTest, stateInvalid)
{
	Piezas temp;
  //      X                O
  temp.dropPiece(0);temp.dropPiece(1);
  temp.dropPiece(2);temp.dropPiece(3);
  temp.dropPiece(0);temp.dropPiece(1);
  ASSERT_EQ(temp.gameState(), Invalid);
}
