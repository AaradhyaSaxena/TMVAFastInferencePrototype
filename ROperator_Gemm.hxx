#ifndef TMVA_SOFIE_ROPERATOR_GEMM
#define TMVA_SOFIE_ROPERATOR_GEMM


#include "SOFIE_common.hxx"
#include "ROperator.hxx"
#include "RModel.hxx"

#include <sstream>
#include <algorithm>

namespace TMVA{
namespace Experimental{
namespace SOFIE{


   template <typename T>
   class ROperator_Gemm final : public ROperator
   {

   private:
      float fAttrAlpha = 1.0;
      float fAttrBeta = 1.0;
      int_t fAttrTransA = 0;
      int_t fAttrTransB = 0;

      bool fCexists;
      std::string fNA;
      std::string fNB;
      std::string fNC;
      std::string fNY;
      std::vector<size_t> fShapeA;
      std::vector<size_t> fShapeB;
      std::vector<size_t> fShapeC;
      std::vector<size_t> fShapeY;

      std::string fType;

   public:

      ROperator_Gemm() = delete;
      ROperator_Gemm(float alpha, float beta, int_t transA, int_t transB, std::string nameA, std::string nameB, std::string nameY):
         fAttrAlpha(alpha), fAttrBeta(beta), fAttrTransA(transA), fAttrTransB(transB), fNA(nameA), fNB(nameB), fNY(nameY) {

         if (std::is_same<T, float>::value) {
            fType = "float";
         }else{
            throw std::runtime_error("TMVA SOFIE Encountered unsupported type parsing a gemm operator");
         }
         fCexists = false;
      }

      const std::vector<std::vector<size_t>> ShapeInference(std::vector<std::vector<size_t>> input){
         if (input.size() > 3) throw std::runtime_error("TMVA SOFIE Gemm Op Shape Inference only need 2 or 3 input tensor");
         for (auto& i: input){
            if (i.size() > 2){
               throw std::runtime_error("TMVA SOFIE Gemm Op Shape Inference only accept input tensor with 2 dimensions");
            }
         }
         std::vector<std::vector<size_t>> ret;
         if (input.size() == 3){
            ret.push_back(input[2]);   //shape of C is shape of Y
            return ret;
         }
         std::vector<size_t> s_a(input[0]);
         std::vector<size_t> s_b(input[1]);
         if (fAttrTransA){
            std::reverse(s_a.begin(), s_a.end());
         }
         if (fAttrTransB){
            std::reverse(s_b.begin(), s_b.end());
         }
         std::vector<size_t> s_y(2);
         s_y[0] = s_a[0];
         s_y[1] = s_b[1];
         ret.push_back(s_y);
         return ret;
      }

      void Initialize(RModel& model){
         if ((model.CheckIfTensorAlreadyExist(fNA) == false) || (model.CheckIfTensorAlreadyExist(fNB) == false) ){   //input must be a graph input, or already initialized intermediate tensor
            throw std::runtime_error("TMVA SOFIE Gemm Op Input Tensor is not found in model");
         }
         if (fCexists){
            if (model.CheckIfTensorAlreadyExist(fNC) == false){   //input must be a graph input, or already initialized intermediate tensor
               throw std::runtime_error("TMVA SOFIE Gemm Op Input Tensor is not found in model");
            }
         }
         fShapeA = model.GetTensorShape(fNA);
         fShapeB = model.GetTensorShape(fNB);
         if (fCexists){
            fShapeC = model.GetTensorShape(fNC);
         }

         if (fCexists){
            fShapeY = fShapeC;
         }else{
            fShapeY = ShapeInference({fShapeA, fShapeB})[0];
         }

         model.AddIntermediateTensor(fNY, model.GetTensorType(fNA), fShapeY);
      }

      std::string Generate(){
         if (fShapeA.empty() || fShapeB.empty() || fShapeY.empty() || (fCexists && fShapeC.empty())){
            throw std::runtime_error("TMVA SOFIE Gemm Op called to Generate without being initialized first");
         }
         std::stringstream out;
         std::string name_a = fNA;


      }

   };


}//SOFIE
}//Experimental
}//TMVA


#endif //TMVA_SOFIE_ROPERATOR_GEMM