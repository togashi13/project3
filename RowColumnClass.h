#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

class RowColumnClass
{
   private:
      int row;
      int col;

   public:
      RowColumnClass();
      //{}default ctor sets both r and c to -99999.

      RowColumnClass(
           int inRow,
           int inCol
           );

      //value ctor

      void setRowCol(
           int inRow,
           int inCol
           );

      void setRow(
           int inRow
           );


      void setCol(
           int inCol
           );

      //simple setters

      int getRow();
      int getCol();

      // simple getters

      void addRowColTo(
           RowColumnClass &inRowCol
           );

      void printRowCol(
           );

      //{}"[<row>,<col>]" no newl.

};

#endif