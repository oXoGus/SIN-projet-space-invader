class Rock {
  private :
  unsigned char row; // coordonnée en y de l'objet 

  unsigned char col; // coordonnée en x de l'objet

  public : 

  unsigned char getRow(); // retourne la coordonnée en y de l'objet 

  unsigned char getCol(); // retourne la coordonnée en x de l'objet 

  Rock(lcd); // constructeur 

  void moove(row, col);  // bouge l'objet de 1 vers la gauche 

  bool isTouch(unsigned char Srow, unsigned char Scol);


}