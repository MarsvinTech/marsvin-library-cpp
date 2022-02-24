#ifndef MARSVIN_LUDECOMPOSITION_HPP_
#define MARSVIN_LUDECOMPOSITION_HPP_

#include <vector>
#include <algorithm>

namespace marsvin {

class LUDecomposition {
    public:
        LUDecomposition();
        template<typename T> static std::vector<marsvin::Matrix<T>> PartialPivoting(const marsvin::Matrix<T>& m1);
};

} // namespace marsvin


template<typename T> std::vector<marsvin::Matrix<T>> marsvin::LUDecomposition::PartialPivoting(const marsvin::Matrix<T>& A) {
    // Reference:
    // [1] Page 237 -> Numerical Linear Algebra: Theory and Applications - Larisa Beilina, Evgenii Karchevskii and Mikhail Karchevskii
    std::vector<marsvin::Matrix<T>> result_;
    if (m1.IsSquare()) {
        // Initial condition
        std::vector<T> diagonal_(A.GetNumberOfRows(),1);
        marsvin::Matrix<T> P(diagonal_);
        marsvin::Matrix<T> L(diagonal_);
        marsvin::Matrix<T> U(A);
        std::vector<T> vec_temp;
        // Loop
        for (int j = 1 ;j < A.GetNumberOfRows();j++) {
            vec_temp = A.GetColumn(j);
            m = std::max_element(vec_temp.begin()+j-1,vec_temp.end()) - vec_temp.begin() + 1;
            if (m != j) {
                P.SwapRows(m,j);
                U.SwapRows(m,j);
                if (j >= 2) {
                    vec_temp = L.GetRow(m);
                    std::vector<T> new_row_j {vec_temp.begin(), vec_temp.begin()+j-2};
                    new_row_j.insert(new_row_j.end(),vec_temp.begin() + j - 1,vec_temp.end());
                    vec_temp = L.GetRow(j);
                    std::vector<T> new_row_m {vec_temp.begin(), vec_temp.begin()+j-2};
                    new_row_m.insert(new_row_m.end(),vec_temp.begin() + j - 1,vec_temp.end());
                    L.SetRow(j,new_row_j); 
                    L.SetRow(m,new_row_m); 
                }
            }
            // Update L
            vec_temp = L.GetColumn(j);
            std::vector<T> new_L_column_j { vec_temp.begin(),vec_temp.begin()+j-1 };
            vec_temp = U.GetColumn(j);
            std::vector<T> L_sub_column = std::transform(vec_temp.begin(),vec_temp.end(),[U,j](T &c){return c/U.GetEntry(j,j)});
            new_L_column_j.insert(new_L_column_j.end(),L_sub_column.begin()+j,L_sub_column.end());
            L.SetColumn(j,new_L_column_j);
            // Ref: https://slaystudy.com/c-divide-vector-by-scalar/
            // Update U
             
        }
    }
}

#endif // MARSVIN_LUDECOMPOSITION_HPP_
