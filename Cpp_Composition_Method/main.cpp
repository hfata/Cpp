/**
 * @file main.cpp
 * @brief Simple program for "compositon" method
 * 
 * @author HFA
 * @date 27/10/2024
 */
#include <iostream>

#define MAX_SQUARES				3

using namespace std;

/**
 * @class Coordinate
 * @brief Class to represent a coordinate in a two-dimensional space
 */
class Coordinate {
public:
    /**
     * @brief Default constructor
     */
    Coordinate() {
		cout << "Default Coordinate Constructor" << endl;
	}
    /**
     * @brief Constructor
     * @param x The x-coordinate
     * @param y The y-coordinate
     */
    Coordinate(const int x, const int y) {
		cout << "Coordinate Constructor" << endl;
        this->x = x;
        this->y = y;
    }
	/**
	 * @brief Destructor
	 */
	~Coordinate() {
		cout << "Coordinate Destructor" << endl;
	}
	/**
	 * @brief Get a copy of the coordinate
	 * @return A copy of the coordinate
	 */
	const Coordinate getCoordinate() const {
		Coordinate tempCoordinate;
		tempCoordinate.x = this->x;
		tempCoordinate.y = this->y;
		return tempCoordinate;
	}
	/**
	 * @brief Get the x-coordinate
	 * @return The x-coordinate
	 */
	const int getCoordinateX() const {
		return this->x;
	}
	/**
	 * @brief Get the y-coordinate
	 * @return The y-coordinate
	 */
	const int getCoordinateY() const {
		return this->y;
	}
private:
    mutable int x;
    mutable int y;
};

/**
 * @class Square
 * @brief Class to represent a square in a two-dimensional space
 */
class Square {
public:
    /**
     * @brief Default constructor
     */
    Square() {
        cout << "Square Constructor" << endl;
    }
	/**
	 * @brief Destructor
	 */
	~Square() {
		cout << "Square Destructor" << endl;
	}
	/**
	 * @brief Set the coordinate of the square
	 * @param coordinate The coordinate to set
	 */
    void setSquareCoordinate(const Coordinate &coordinate) {
        this->coordinate = coordinate;
    }
	/**
	 * @brief Get the coordinate of the square
	 * @return The coordinate of the square
	 */
    const Coordinate &getSquareCoordinate() const {
        return this->coordinate;
    }
	Square& operator=(Square&&) noexcept = default;
private:
    Coordinate coordinate;
};

/**
 * @class Board
 * @brief Class to represent a board with multiple squares
 */
class Board {
public:
    /**
     * @brief Constructor
     */
    Board();
    /**
     * @brief Destructor
     */
    ~Board();
    /**
     * @brief Set the coordinate of a square
     * @param index The index of the square
     * @param coordinate The coordinate to set
     */
    void setSquare(const int index, const Coordinate &coordinate) {
        if (index >= 0 && index < MAX_SQUARES) {
            m_square[index].setSquareCoordinate(coordinate);
        } else {
			throw out_of_range("Index out of bounds");
        }
    }
	/**
	 * @brief Get a square
	 * @param index The index of the square
	 * @return The square at the given index
	 */
	const Square &getSquare(const int index) const {
		if (index >= 0 && index < MAX_SQUARES) {
			return m_square[index];
		} else {
			throw out_of_range("Index out of bounds");
		}
	}
    /**
     * @brief Move assignment operator
     * @param board The board to move
     * @return A reference to the current board
     */
    Board& operator=(Board &&board) noexcept {
		cout << "Move assignment operator" << endl;
        if (this != &board) {
            delete[] m_square;
            m_square = board.m_square;
            board.m_square = nullptr;
        }
        return *this;
    }
private:
    Square* m_square;
};

/**
 * @brief Constructor
 */
Board::Board() {
    cout << "Board Constructor" << endl;
    m_square = new Square[MAX_SQUARES];
}

/**
 * @brief Destructor
 */
Board::~Board() {
    cout << "Board Destructor" << endl;
    delete[] m_square;
}

int main() {
    Board board;
    board.setSquare(0, Coordinate(1, 2));
    board.setSquare(1, Coordinate(3, 4));

    const Square &square0 = board.getSquare(0);
    const Square &square1 = board.getSquare(1);

    cout << "Coordinate: " << square0.getSquareCoordinate().getCoordinateX() << ", " << square0.getSquareCoordinate().getCoordinateY() << endl;
    cout << "Coordinate: " << square1.getSquareCoordinate().getCoordinateX() << ", " << square1.getSquareCoordinate().getCoordinateY() << endl;

    return 0;
}

