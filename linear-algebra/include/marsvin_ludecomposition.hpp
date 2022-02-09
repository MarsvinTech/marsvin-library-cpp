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
    std::vector<marsvin::Matrix<T>> result_;
    if (m1.IsSquare()) {
        // Initial condition
        std::vector<T> diagonal_(A.GetNumberOfRows(),1);
        marsvin::Matrix<T> P(diagonal_);
        marsvin::Matrix<T> L(diagonal_);
        // Loop
        for (int j = 1 ;j < A.GetNumberOfRows();j++) {
            m = std::max_element(A.GetColumn(j).begin()+j-1,A.GetColumn(j).end()) - A.GetColumn(j).begin() + 1;
            if (m != j) {
                P.SwapRows(m,j);
                U.SwapRows(m,j);
                if (j >= 2) {
                    
                }
            }
            
        }
    }
}

#endif // MARSVIN_LUDECOMPOSITION_HPP_
