#ifndef INC_MATRIX_3X3_H
#define INC_MATRIX_3X3_H
class Matrix_3x3 {
  public:
    Matrix_3x3();
    Matrix_3x3(double*);
    Matrix_3x3(double,double,double);

    int Diagonalize( double*, double* );
    int Diagonalize_Sort(double *, double *);
    int Diagonalize_Sort_Chirality(double*, double*);
    void Print(const char*);

  private:
    double M_[9];
    // The following three variables are set during Diagonalize_Sort. They
    // indicate the original ordering of the eigenvalues/eigenvectors. This
    // information can be used to prevent reflections when e.g. aliging
    // coordinates along principal axes (see e.g. Action_Principal).
    int i1_;
    int i2_;
    int i3_; 
    static const int MAX_ITERATIONS;
};
//    int Diagonalize( double*, double*, double* );
//    int Diagonalize_Sort(double*, double *, double *);
#endif