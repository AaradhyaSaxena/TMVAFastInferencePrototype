#include "testCaseBatchNorm_1.hxx"

#include <algorithm>
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>

int main(){
   const int batchsize =2;
   float inputss[60 * batchsize] = {
      -8.746581152081489563e-03,
      -6.324751377105712891e-01,
      -5.249168872833251953e-01,
      3.948761224746704102e-01,
      -1.845381259918212891e+00,
      -1.316573143005371094e+00,
      -8.555153012275695801e-01,
      2.002608060836791992e+00,
      -1.428613901138305664e+00,
      -1.056838870048522949e+00,
      -1.238745570182800293e+00,
      -1.027959346771240234e+00,
      -3.469950556755065918e-01,
      -1.429911017417907715e+00,
      7.106134295463562012e-01,
      7.311050891876220703e-01,
      1.485693901777267456e-01,
      -4.115794301033020020e-01,
      -5.546666979789733887e-01,
      5.788854956626892090e-01,
      7.297990471124649048e-02,
      -1.103912115097045898e+00,
      -4.033167958259582520e-01,
      6.284976005554199219e-01,
      1.815155744552612305e-01,
      1.324420809745788574e+00,
      -3.501448333263397217e-01,
      -4.890034794807434082e-01,
      9.548899531364440918e-01,
      8.036095499992370605e-01,
      -1.067348383367061615e-02,
      -1.521765589714050293e+00,
      -4.019072055816650391e-01,
      4.414758682250976562e-01,
      -1.302858352661132812e+00,
      7.406160235404968262e-01,
      -7.753484845161437988e-01,
      1.068183034658432007e-01,
      1.081735849380493164e+00,
      -1.354755043983459473e+00,
      8.765058219432830811e-02,
      -8.205518722534179688e-01,
      -4.876237809658050537e-01,
      -5.751024484634399414e-01,
      -9.284884333610534668e-01,
      -4.600801765918731689e-01,
      1.581327766180038452e-01,
      -1.233272701501846313e-01,
      5.081380605697631836e-01,
      7.010759115219116211e-01,
      1.728187650442123413e-01,
      1.716399490833282471e-01,
      8.161317706108093262e-01,
      2.084572101011872292e-03,
      -1.739165484905242920e-01,
      -1.585417985916137695e+00,
      1.652097105979919434e+00,
      -1.083292722702026367e+00,
      -1.081893444061279297e+00,
      2.359067440032958984e+00,
      9.531813114881515503e-02,
      7.315919995307922363e-01,
      -1.159043550491333008e+00,
      -6.761702150106430054e-02,
      5.126855373382568359e-01,
      4.097590744495391846e-01,
      1.026593986898660660e-02,
      -8.812121152877807617e-01,
      1.632959842681884766e-01,
      -2.631781697273254395e-01,
      -6.505224108695983887e-01,
      1.060783028602600098e+00,
      -1.739174365997314453e+00,
      7.105301618576049805e-01,
      1.005764603614807129e-01,
      -5.401186347007751465e-01,
      -1.187115550041198730e+00,
      -4.957436025142669678e-02,
      -2.221029281616210938e+00,
      -3.373483657836914062e+00,
      4.599675834178924561e-01,
      -1.759204864501953125e-01,
      3.922293782234191895e-01,
      -5.248783826828002930e-01,
      -6.712627410888671875e-01,
      1.404041051864624023e+00,
      1.869109988212585449e+00,
      -2.998682558536529541e-01,
      -8.273292183876037598e-01,
      1.473095536231994629e+00,
      -8.079558610916137695e-01,
      5.404236540198326111e-02,
      7.124262452125549316e-01,
      7.163481116294860840e-01,
      -1.852418780326843262e-01,
      1.793446660041809082e+00,
      8.894287347793579102e-01,
      -6.703860163688659668e-01,
      2.617742717266082764e-01,
      -3.840980529785156250e-01,
      -1.860538959503173828e+00,
      8.623432368040084839e-02,
      3.331827402114868164e+00,
      -8.412842154502868652e-01,
      -2.077336072921752930e+00,
      -8.300220966339111328e-01,
      1.538884997367858887e+00,
      -5.781504511833190918e-01,
      -4.098339378833770752e-01,
      -1.044347763061523438e+00,
      1.969988048076629639e-01,
      9.510769248008728027e-01,
      1.103198766708374023e+00,
      -6.053544282913208008e-01,
      -1.367871880531311035e+00,
      -9.233094453811645508e-01,
      -1.860064983367919922e+00,
      -2.736594974994659424e-01,
      -1.435602754354476929e-01,
      -1.240384936332702637e+00,
   };

   auto t1 = std::chrono::high_resolution_clock::now();
   auto out = TMVA_SOFIE_testCaseBatchNorm_1::infer(inputss);
   auto t2 = std::chrono::high_resolution_clock::now();
   for (auto& i: out){
      std::cout << i << ",";
   }
   //free(inputss);
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
   std::cout << std::endl << duration << std::endl;
}
