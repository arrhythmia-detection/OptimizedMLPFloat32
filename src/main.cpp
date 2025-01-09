#include <Arduino.h>
#include <esp32_tflm_wrapper.h>
#include "floating_point_model_mlp.h"

#define ARENA_SIZE 5700
#define TF_NUM_OPS 2
#define TF_NUM_INPUTS 900
#define TF_NUM_OUTPUTS 21

Eloquent::TF::Sequential<TF_NUM_OPS, ARENA_SIZE> fp32MLP;

void setup() {
    Serial.begin(115200);
    Serial.println("__TENSORFLOW FP 32 MLP__");
    delay(3000);


    fp32MLP.setNumInputs(TF_NUM_INPUTS);
    fp32MLP.setNumOutputs(TF_NUM_OUTPUTS);

    // network configuration
    fp32MLP.resolver.AddFullyConnected();
    fp32MLP.resolver.AddSoftmax();
    // done with network configuration


    while (!fp32MLP.begin(GeneratedTfLiteFiles_floating_point_model_mlp_tflite).isOk())
        Serial.println(fp32MLP.exception.toString());
}

// Just for employability check hardcoding the input here.

float inputs[] = {
    7.222572445849145817e-01, -5.348170647523494692e-01, -1.730311267895436600e-01, 1.798285201880649442e+00,
    1.770310251768575149e+00, 1.416162888893455207e-01, -8.146770804702372359e-01, -5.634667817339429619e-02,
    5.558587297352766132e-01, 1.772929261449253391e-01, -5.444094478745256094e-01, 4.427477079701166995e-02,
    1.654038973092199827e+00, 1.780894361693146744e+00, 6.070267243622138459e-02, -8.144507598641681501e-01,
    -3.020482541812759616e-02, 5.276392194698956706e-01, 5.985577099443501782e-03, -5.611961183383340490e-01,
    6.283859119385308556e-02, 1.466218362690572485e+00, 1.618283945579274574e+00, 2.619539483121256784e-02,
    -8.156578030965363491e-01, -5.696838460065062511e-03, 4.999967953040113655e-01, 5.985577099443501782e-03,
    -5.611961183383340490e-01, 6.283859119385308556e-02, 1.198761813478655291e+00, 1.412374897955791297e+00,
    2.397272344999592034e-03, -8.174683679450888141e-01, 1.624364510239091966e-02, 4.747781327560124942e-01,
    -1.181835081147312450e-01, -5.771834235419611714e-01, 1.697503491930371297e-02, 9.388180886828032534e-01,
    1.279592427992984449e+00, -9.501788898106896739e-03, -8.201842152179174006e-01, 3.608344406844154334e-02,
    4.515215629463018576e-01, -1.549743481781904464e-01, -6.275434349333863793e-01, -4.636035231697874237e-02,
    7.314641347994066400e-01, 1.243991330973971188e+00, 4.285408057156165490e-02, -8.249369479453674270e-01,
    5.475619603648918671e-02, 4.301116686549801837e-01, -1.549743481781904464e-01, -6.275434349333863793e-01,
    -4.636035231697874237e-02, 6.668538448212468772e-01, 1.186259822294489785e+00, 1.749336603700436810e-01,
    -8.316511259254159016e-01, 7.552963260094219811e-02, 4.095096949029536360e-01, -5.366793138365795190e-01,
    -7.786234691076621139e-01, -6.820014101914510796e-02, 6.413102418066255472e-01, 8.773962508592650922e-01,
    2.879747421795553208e-01, -8.376109018852341270e-01, 1.009712571574071099e-01, 3.908698138892153229e-01,
    -4.044622323585230217e-01, -8.529644383045280609e-01, -1.064197712479362512e-01, 6.908948829526551094e-01,
    7.850258369720950480e-01, 3.748378892542327256e-01, -8.403267491580627135e-01, 1.273465193122743921e-01,
    3.769043302813990248e-01, -4.044622323585230217e-01, -8.529644383045280609e-01, -1.064197712479362512e-01,
    7.209461806169155107e-01, 8.264000848590566939e-01, 4.379029138426971390e-01, -8.423636346126841534e-01,
    1.546554190655440864e-01, 3.647278135820219980e-01, -2.354543108170074062e-01, -9.177130243792176456e-01,
    -3.390135209260080607e-01, 7.059205317847853101e-01, 1.065985845878903993e+00, 4.545615995830462053e-01,
    -8.462865251178810500e-01, 1.835981846160179287e-01, 3.514548332936015540e-01, -4.102108011184385505e-01,
    -9.984489156575342417e-01, -3.477494364068745569e-01, 6.939000127190811940e-01, 1.221860919313503269e+00,
    4.462322567128716444e-01, -8.543586267343438179e-01, 2.139414065640953544e-01, 3.345462105783528761e-01,
    -4.102108011184385505e-01, -9.984489156575342417e-01, -3.477494364068745569e-01, 6.893923180694421227e-01,
    1.110246669199839609e+00, 4.331432893454545408e-01, -8.644676138054279146e-01, 2.440512191125721875e-01,
    3.156754951248159635e-01, -4.401033586699991118e-01, -1.132742279368001537e+00, -4.078088553378320658e-01,
    7.269564401497675687e-01, 9.149217315009279261e-01, 3.807874198757859596e-01, -8.729169164320057517e-01,
    2.711267094662412891e-01, 2.988822896294666132e-01, -3.446771172554018436e-01, -1.238258493711940300e+00,
    -4.940760207113892299e-01, 8.546744552228742187e-01, 7.378784382171853506e-01, 3.034435217955937514e-01,
    -8.783486109776629247e-01, 2.916667366310936593e-01, 2.857824351708950772e-01, -3.446771172554018436e-01,
    -1.238258493711940300e+00, -4.940760207113892299e-01, 9.102693559017558389e-01, 8.004209059532900739e-01,
    2.844050238066233582e-01, -8.812153386545376055e-01, 3.063715288059312147e-01, 2.751063423302090860e-01,
    -1.618726306900890310e-01, -1.247051511573935123e+00, -5.213757565890971835e-01, 9.884027298288328156e-01,
    9.081863888216550329e-01, 2.760756809364488529e-01, -8.848364683516423135e-01, 3.189756363843633813e-01,
    2.633914945104292582e-01, -1.618726306900890310e-01, -1.247051511573935123e+00, -5.213757565890971835e-01,
    7.780436461790102287e-01, 8.725852918026416605e-01, 3.141526769143896392e-01, -8.896646412811154425e-01,
    3.325133815611979182e-01, 2.501185142220088142e-01, -1.618726306900890310e-01, -1.247051511573935123e+00,
    -5.213757565890971835e-01, 7.630179973468800281e-01, 9.062620051990056824e-01, 3.260517381574961071e-01,
    -8.963033790591408145e-01, 3.467513549368342329e-01, 2.371340769833366335e-01, 1.117592422818886599e-01,
    -1.199089595963053867e+00, -7.627054217480354614e-01, 8.456590659235960761e-01, 9.332033759160969222e-01,
    2.498977462016145623e-01, -9.039228394634655217e-01, 3.591220531156658069e-01, 2.236879708650671983e-01,
    -3.540411797194808335e-02, -1.155124506653079530e+00, -7.910971470608517686e-01, 1.060525844223057623e+00,
    9.312789922934475717e-01, 1.808831909915969149e-01, -9.109387782516059628e-01, 3.663577445032842328e-01,
    2.101264475268984910e-01, -3.540411797194808335e-02, -1.155124506653079530e+00, -7.910971470608517686e-01,
    1.212284897427572394e+00, 7.869502205947445095e-01, 8.569070104674501864e-02, -9.154651903729870144e-01,
    3.712593418948967883e-01, 1.967380500185787195e-01, 1.646460748731112533e-01, -1.093573381619115326e+00,
    -7.364976753054358616e-01, 1.401608072712412723e+00, 9.485984448972919481e-01, 4.642379894449359667e-02,
    -9.170494346154702825e-01, 3.717261606940979735e-01, 1.845615333192016927e-01, 1.657957886250943369e-01,
    -1.007241933519529287e+00, -7.616134323129272188e-01, 1.605956896829383140e+00, 1.247840098219269889e+00,
    1.011594806627834631e-01, -9.196898416862758774e-01, 3.714927512944973809e-01, 1.689225000228453955e-01,
    1.657957886250943369e-01, -1.007241933519529287e+00, -7.616134323129272188e-01, 1.783259553048519352e+00,
    1.445089419540830811e+00, 1.094888235329579962e-01, -9.251969764339561531e-01, 3.747604828889056772e-01,
    1.479742746111209484e-01, 4.277641716290268847e-02, -8.489676120036212525e-01, -8.533405448620259293e-01,
    1.924500652070542994e+00, 1.592304766673507954e+00, 4.404398669587230447e-02, -9.326655564342347660e-01,
    3.794286708809175845e-01, 1.231018637228200041e-01, -5.609896550764387202e-02, -8.217891931574552444e-01,
    -8.740883441290839828e-01, 2.112321262472170336e+00, 1.642338740862391733e+00, -5.114850324897961265e-02,
    -9.411148590608124920e-01, 3.815293554773229734e-01, 9.545943955693565741e-02, -5.609896550764387202e-02,
    -8.217891931574552444e-01, -8.740883441290839828e-01, 2.312162391939501571e+00, 1.543232984295948906e+00,
    -1.891776136690148935e-01, -9.478290370408609666e-01, 3.796620802805181771e-01, 6.700909485175615687e-02,
    -1.078360843468833541e-01, -7.890152174900197934e-01, -8.981121117014669863e-01, 2.531536864888602523e+00,
    1.536497641616676013e+00, -3.307764424619820676e-01, -9.509220853238046223e-01, 3.719595700936985661e-01,
    3.953979651572077370e-02, -1.250817906266298574e-01, -7.922126785307451735e-01, -9.679994355483992896e-01,
    2.737388253888785705e+00, 1.676977646070080485e+00, -4.259689324068339777e-01, -9.522800089602189155e-01,
    3.584218249168640291e-01, 1.149341208018884834e-02, -1.250817906266298574e-01, -7.922126785307451735e-01,
    -9.679994355483992896e-01, 2.896660131509365854e+00, 1.855945322976472411e+00, -4.854642386223664285e-01,
    -9.541660140107943722e-01, 3.416163481456211404e-01, -1.932298563292647597e-02, -2.515503033447707981e-01,
    -8.153942710760043733e-01, -1.126337903639105686e+00, 3.034896100764963300e+00, 2.003160670109149333e+00,
    -5.092623611085793645e-01, -9.572590622937380278e-01, 3.229435961775734554e-01, -5.342877411317208808e-02,
    -3.803182435668779338e-01, -8.137955405556417388e-01, -1.196225227486037879e+00, 3.101008955626336050e+00,
    2.012782588222396196e+00, -4.949834876168516251e-01, -9.606538713847737609e-01, 3.047376630087270111e-01,
    -9.001603282125283934e-02, -3.803182435668779338e-01, -8.137955405556417388e-01, -1.196225227486037879e+00,
    3.107019215159188441e+00, 1.937731626939070750e+00, -4.830844263737451572e-01, -9.631433980515332616e-01,
    2.881655956370847704e-01, -1.272957948487294377e-01, -3.584736822791990685e-01, -7.706298165058486083e-01,
    -1.305424170996869693e+00, 3.033393535881750314e+00, 1.894432995429459865e+00, -4.533367732659789318e-01,
    -9.645013216879475548e-01, 2.729939846630460298e-01, -1.638830535568101820e-01, -2.595982996086524941e-01,
    -7.610374333836723570e-01, -1.435370913774759671e+00, 2.923706299407200060e+00, 1.909828064410654891e+00,
    -3.700433445642334895e-01, -9.663118865365000199e-01, 2.596896488858120855e-01, -2.004703122648909264e-01,
    -2.595982996086524941e-01, -7.610374333836723570e-01, -1.435370913774759671e+00, 2.865106268961892244e+00,
    1.984879025693980337e+00, -2.867499158624881028e-01, -9.700838966376508221e-01, 2.489528165041846874e-01,
    -2.378077829023171885e-01, -2.228074595451933204e-01, -8.601587256461601383e-01, -1.677792568368806414e+00,
    2.890649871976513907e+00, 1.990652176561928499e+00, -2.403435770143728112e-01, -9.754401509812850035e-01,
    2.400832593193620579e-01, -2.764148429586358313e-01, -2.262566008011425989e-01, -9.392958864041142109e-01,
    -1.743311934475305414e+00, 3.018367887049620002e+00, 2.066665329656578454e+00, -1.963170504148787909e-01,
    -9.804946445168271074e-01, 2.330809773313441968e-01, -3.161760752139475272e-01, -2.262566008011425989e-01,
    -9.392958864041142109e-01, -1.743311934475305414e+00, 3.143080772356300567e+00, 2.255254924676217243e+00,
    -1.570501483126273690e-01, -9.855491380523692113e-01, 2.267789235421281135e-01, -3.580148174274467854e-01,
    -1.837171919777679241e-01, -9.456908084855649710e-01, -1.694172409895431164e+00, 3.267793657662981133e+00,
    2.594908634073831877e+00, -1.225428707076185314e-01, -9.924896366384866608e-01, 2.214105073513144284e-01,
    -4.043548312170190950e-01, -3.090359909439257535e-01, -9.169136591190362173e-01, -1.613365191697415435e+00,
    3.339916772057206273e+00, 2.901847821886407441e+00, -1.499107115667634715e-01, -1.002749504113616963e+00,
    2.165089099597019007e-01, -4.572159179309023269e-01, -3.090359909439257535e-01, -9.169136591190362173e-01,
    -1.613365191697415435e+00, 3.430070665049987255e+00, 3.067344813434253581e+00, -2.046463932850533241e-01,
    -1.015197137447414466e+00, 2.088063997728822618e-01, -5.142320245611606833e-01, -7.930654805288106513e-01,
    -7.810215648882061767e-01, -1.053174611486848100e+00, 3.452609138298182501e+00, 2.954768371509265190e+00,
    -1.903675197933255570e-01, -1.026362287346821001e+00, 1.983029767908554564e-01, -5.710750053615699651e-01,
    -8.459523131200332724e-01, -7.242666314153300977e-01, -7.343136964352192653e-01, 3.499188649677785978e+00,
    2.929751384414823079e+00, -9.755484209709490429e-02, -1.033755427145076622e+00, 1.896668290056334194e-01,
    -6.244554695650000875e-01, -8.459523131200332724e-01, -7.242666314153300977e-01, -7.343136964352192653e-01,
    3.452609138298182501e+00, 2.771951927357574341e+00, 1.548623971241673038e-02, -1.038508159872526537e+00,
    1.856988692124232898e-01, -6.751813377107460656e-01, -9.862173908619714657e-01, -5.540018309967018606e-01,
    -2.855060386057004518e-01, 3.137070512823448620e+00, 2.340889995884114505e+00, -5.590812774622220399e-02,
    -1.040092404115009916e+00, 1.868659162104262805e-01, -7.208865567908721017e-01, -9.885168183659376329e-01,
    -5.939700940057696110e-01, -8.894794028620316151e-02, 2.756921597370554977e+00, 1.957937654976889208e+00,
    -2.784205729923135419e-01, -1.038130958862411468e+00, 1.854654598128226972e-01, -7.582240274282984194e-01,
    -9.885168183659376329e-01, -5.939700940057696110e-01, -8.894794028620316151e-02, 2.376772681917661334e+00,
    1.515329421767533047e+00, -5.199715162273752522e-01, -1.033453666336984433e+00, 1.756622650295976973e-01,
    -7.873668754528737601e-01, -1.029906513437329307e+00, -7.754260080669367339e-01, 2.648566366888919776e-01,
    2.023669934362602341e+00, 1.170864753313294759e+00, -6.282529735396443771e-01, -1.025758765730636846e+00,
    1.583899694591536234e-01, -8.081419750347492714e-01, -8.689465881596952768e-01, -7.530437807818588514e-01,
    2.430168479867255982e-01, 1.589428683114040064e+00, 1.060212695010955830e+00, -4.985532059897835877e-01,
    -1.017384903306082000e+00, 1.399506268907065587e-01, -8.233770480614579501e-01, -8.689465881596952768e-01,
    -7.530437807818588514e-01, 2.430168479867255982e-01, 1.324977263668548844e+00, 8.446817292742256900e-01,
    -2.926994464840413368e-01, -1.011349687144240672e+00, 1.282801569106767903e-01, -8.361883594702811395e-01,
    -4.355045036620667220e-01, -6.115561297297593679e-01, 7.485047498004457345e-02, 1.165705386047968917e+00,
    5.502510350088714031e-01, -1.118337155888226991e-01, -1.004560068962169206e+00, 1.259460629146708366e-01,
    -8.449023595726790070e-01, -2.331548833130412113e-01, -5.803808845826865515e-01, -6.820014101914510796e-02,
    1.156689996748690774e+00, 2.404252717623220625e-01, -1.046942788429588017e-01, -9.850210566382080479e-01,
    1.329483449026886976e-01, -8.509040550074430387e-01, -2.331548833130412113e-01, -5.803808845826865515e-01,
    -6.820014101914510796e-02, 1.135654088383708515e+00, 3.539639054986351563e-01, -6.185765836777545185e-02,
    -9.957335653254764107e-01, 1.294472039086797532e-01, -8.492882139288526755e-01, -1.815841169220158702e-02,
    -5.955688245261322455e-01, -1.719391373544353341e-01, 1.309951614836418754e+00, 3.077786985550501897e-01,
    -1.832280830474616595e-01, -9.731015047185714861e-01, 1.331817543022892902e-01, -8.514234324969899292e-01,
    4.737527217083508518e-02, -6.587186800804591957e-01, -1.610192430033521582e-01, 1.479741446639489810e+00,
    5.685326794240403991e-01, -2.403435770143728112e-01, -9.611819527989349243e-01, 1.292137945090791606e-01,
    -8.539049027248249990e-01, 4.737527217083508518e-02, -6.587186800804591957e-01, -1.610192430033521582e-01,
    1.601449202179744180e+00, 7.571222744436791885e-01, -2.855600097381774671e-01, -9.512238461318966998e-01,
    1.224449219206618922e-01, -8.605413928690351932e-01, -6.661274172370593508e-03, -6.651136021619099559e-01,
    -3.728651934143659141e-01, 1.494767095471619900e+00, 9.466740612746425976e-01, -3.319663485862927033e-01,
    -9.438307063336410785e-01, 1.147424117338422395e-01, -8.711020684898219679e-01, -6.414696177152556800e-02,
    -6.747059852840862071e-01, -4.187287496889152694e-01, 1.272387492756093197e+00, 1.035195707916513941e+00,
    -4.533367732659789318e-01, -9.411902992628355946e-01, 1.049392169506172257e-01, -8.854138037573361375e-01,
    -6.414696177152556800e-02, -6.747059852840862071e-01, -4.187287496889152694e-01, 8.787154933542824509e-01,
    7.638576171229519707e-01, -6.246832551667124145e-01, -9.416429404749736554e-01, 8.976760597657852669e-02,
    -9.000717906845483451e-01, -2.735612170806638391e-02, -7.818209301483876050e-01, -3.837850877654490622e-01,
    4.730229748867675332e-01, 5.233096642917800523e-01, -7.948398309431352615e-01, -9.426991033032958711e-01,
    6.595984721731777689e-02, -9.100553802058385378e-01, 1.288385961134209945e-02, -8.401745941416263186e-01,
    -3.761411617196908641e-01, 1.634946089448858497e-01, 5.560241858768194545e-01, -8.947919453852297700e-01,
    -9.454149505761244576e-01, 3.374935007243558965e-02, -9.168072875699480040e-01, 1.288385961134209945e-02,
    -8.401745941416263186e-01, -3.761411617196908641e-01, -4.536190982172368102e-02, 7.292187119152632180e-01,
    -9.007414760067830040e-01, -9.518273677480808548e-01, -2.195697466056129379e-03, -9.244825326932520904e-01,
    -1.641720581940552259e-01, -9.289041380217565314e-01, -2.265386091098512411e-01, -1.475363218802089038e-01,
    6.099069273110019340e-01, -8.579048555315996749e-01, -9.610310723948888301e-01, -3.697369800654486810e-02,
    -9.334273672354485019e-01, -4.115268673186357751e-02, -9.352990601032074025e-01, -1.435474120416190547e-01,
    -2.331825202233509253e-01, 2.288789700264257931e-01, -8.257773901752121226e-01, -9.725734233044103227e-01,
    -1.034953768927145967e-01, -9.401792745995579681e-01, -4.115268673186357751e-02, -9.352990601032074025e-01,
    -1.435474120416190547e-01, -1.971209630262384938e-01, 3.414554119514142116e-01, -8.364865452940078994e-01,
    -9.682733317890984681e-01, -7.011783274982943959e-02, -9.390251024005649150e-01, 2.347786137440803222e-01,
    -9.360984253633887198e-01, -1.653872007437854341e-01, -2.767569018365284572e-01, 4.020734960648695289e-01,
    -7.936499248188245703e-01, -9.763454334055611250e-01, -1.368729210355997539e-01, -9.401215659896083876e-01,
    1.726940711369929493e-01, -9.856590714946326104e-01, -2.145267253236597671e-01, -2.557209934715461985e-01,
    8.302488521043553948e-01, -6.758492185120703599e-01, -9.831350515876325913e-01, -1.688500087808813555e-01,
    -9.437572084164365105e-01, 1.726940711369929493e-01, -9.856590714946326104e-01, -2.145267253236597671e-01,
    -2.812645964861675285e-01, 1.157394067954749195e+00, -5.401999203406563366e-01, -9.943756416890621175e-01,
    -1.949918615361480589e-01, -9.540293409874749386e-01, -3.469765447593680663e-01, -1.045611466008234069e+00,
    -2.407344717662593947e-01, -2.662389476540373279e-01, 1.166053794256671328e+00, -3.629039078183696199e-01,
    -1.008332079063320119e+00, -2.136646135041957162e-01, -9.686296193047374548e-01, -4.998884737731202899e-01,
    -1.066394962772949428e+00, -2.724021653844005963e-01, -2.917825506686586579e-01, 6.108691191223266648e-01,
    -2.022665810364320249e-01, -1.020855152599140725e+00, -2.234678082874207161e-01, -9.814409307135607552e-01,
    -4.998884737731202899e-01, -1.066394962772949428e+00, -2.724021653844005963e-01, -2.977928102015107159e-01,
    -8.094679322012354739e-02, -1.439611809452102098e-01, -1.027267569771097122e+00, -2.260353116830272624e-01,
    -9.852496989702378416e-01, -9.059037806713686469e-02, -1.127146722546732205e+00, -3.226336793993832552e-01,
    -4.134903062089131387e-01, -3.849994055987247532e-01, -1.058841849672694513e-01, -1.027720210983235294e+00,
    -2.262687210826278550e-01, -9.794788379752724650e-01, 2.553071088315619561e-02, -1.182302925499245427e+00,
    -3.455654575366579606e-01, -3.879467031942918087e-01, -1.194344656731110427e-01, -1.094539033402014000e-01,
    -1.027418450175143105e+00, -2.274357680806308457e-01, -9.711110895325726355e-01, 2.553071088315619561e-02,
    -1.182302925499245427e+00, -3.455654575366579606e-01, -3.083107643840018453e-01, 2.327277372717245496e-01,
    -3.092009913569858034e-02, -1.029681656235833742e+00, -2.295364526770362068e-01, -9.671869040559961661e-01,
    -3.343296934875539805e-01, -1.043213370227690007e+00, -3.652212673686076605e-01, -2.376902148729899966e-01,
    2.105973256112567416e-01, 1.309071337705496885e-01, -1.034057187953168588e+00, -2.260353116830272624e-01,
    -9.678216987654423287e-01, -2.894908571602131109e-01, -8.849390487117820836e-01, -4.067168659027237676e-01,
    -3.323518025154101330e-01, -1.685062480506701044e-01, 4.521817873344249339e-01, -1.038809920680618726e+00,
    -1.912573111425385219e-01, -9.651093940978086039e-01, -2.894908571602131109e-01, -8.849390487117820836e-01,
    -4.067168659027237676e-01, -2.376902148729899966e-01, -1.647994186136949799e-02, 3.010637095469724800e-01,
    -1.037225676438135347e+00, -2.129643853053939107e-01, -9.678216987654423287e-01, -5.954810676359317129e-02,
    -6.930913862682573923e-01, -5.257437143295304871e-01, -4.210031306249782390e-01, -1.983341942017354254e-01,
    4.866890649394337021e-01, -1.040318724721079002e+00, -1.639484113892688555e-01, -9.608389569615342074e-01,
    -4.690125549177907860e-02, -7.090786914718844036e-01, -5.879871121307046478e-01, -5.216749778002504057e-01,
    -1.117369311825135436e-01, 3.926864811188924831e-01, -1.043034571993907589e+00, -1.371063304352003742e-01,
    -9.567993542650583549e-01, -4.690125549177907860e-02, -7.090786914718844036e-01, -5.879871121307046478e-01,
    -5.922955273112623376e-01, -1.117369311825135436e-01, 1.785033787429756158e-01, -1.047711864519334624e+00,
    -1.163328938707473559e-01, -9.540293409874749386e-01, -4.883913362532892877e-01, -8.993276233950464604e-01,
    -6.895421295957782082e-01, -5.802750082455581104e-01, -2.820448817869832259e-01, -9.993465434571620343e-02,
    -1.052615477650830744e+00, -1.051292426899187726e-01, -9.507399502203447428e-01, -5.734701539000386372e-01,
    -9.233085812004870885e-01, -7.332217070001109116e-01, -5.412083212820196776e-01, -4.504284487688035021e-01,
    -2.522426382574792791e-01, -1.055029564115567142e+00, -1.030285580935134115e-01, -9.445651289557317476e-01,
    -5.734701539000386372e-01, -9.233085812004870885e-01, -7.332217070001109116e-01, -5.081518938513333028e-01,
    -4.850673539764922548e-01, -2.260647035226450163e-01, -1.055557645529728195e+00, -1.046624238907175736e-01,
    -9.363705063428807707e-01, -4.194085111343033301e-01, -9.049231802163160143e-01, -8.238568301141013794e-01,
    -5.847827028951971817e-01, -5.312525609200773324e-01, -1.273024952048611436e-01, -1.055859406337820383e+00,
    -1.046624238907175736e-01, -9.279450492902313608e-01, -3.412279759994525929e-01, -9.105187370375854572e-01,
    -7.889131681906351723e-01, -7.200135423843688764e-01, -5.860974941655845427e-01, -5.828793999484350313e-02,
    -1.056764688762096505e+00, -1.013946922963092356e-01, -9.188847975281355662e-01, -3.412279759994525929e-01,
    -9.105187370375854572e-01, -7.889131681906351723e-01, -8.672649009392444652e-01, -6.707703735621569630e-01,
    -1.664122564397078896e-02, -1.058273492802556781e+00, -9.555945730629435142e-02, -9.086703735670468296e-01,
    -1.779686232178524230e-01, -9.249073117208498340e-01, -7.474175696565190652e-01, -9.453982748663214419e-01,
    -6.871276343546767196e-01, 4.285408057156165490e-02, -1.060385818459201435e+00, -8.855717531827649036e-02,
    -8.973017774069649288e-01, -1.400280694024101380e-01, -9.265060422412124685e-01, -7.386816541756524579e-01,
    -1.010008564844481205e+00, -7.843090072984700845e-01, 1.404263827650348850e-01, -1.065138551186651350e+00,
    -6.778373875382348590e-02, -8.732372870579591106e-01, -1.400280694024101380e-01, -9.265060422412124685e-01,
    -7.386816541756524579e-01, -9.814598320634339013e-01, -7.121446214491186089e-01, 1.094888235329579962e-01,
    -1.062799904923937833e+00, -7.922079933425266174e-02, -8.855869295871851010e-01, -2.965554921203258573e-02,
    -9.169136591190362173e-01, -6.862661612904532582e-01, -1.005500870194842244e+00, -8.449270914119254572e-01,
    1.201979786517538423e-01, -1.066647355227111627e+00, -5.564644997459251147e-02, -8.595603464998911036e-01,
    1.518328711530829780e-02, -9.496876347864717793e-01, -6.818982035500199546e-01, -9.183521069684871252e-01,
    -8.160613370721847559e-01, 5.832286018760009239e-02, -1.067099996439249798e+00, -4.514302699256571294e-02,
    -8.449600681826285875e-01, 1.518328711530829780e-02, -9.496876347864717793e-01, -6.818982035500199546e-01,
    -7.545725346982682380e-01, -6.688459899395076125e-01, -1.069169502241754631e-02, -1.066873675833180712e+00,
    -3.860756380374903707e-02, -8.310522931847619255e-01, -3.195497671599878409e-02, -9.888565325353581015e-01,
    -7.430496119160857615e-01, -6.238493898587357256e-01, -5.735890006183635981e-01, -5.471822162191156136e-02,
    -1.066571915025088746e+00, -3.580665100854189126e-02, -8.192797367550325172e-01, -5.379953800367767713e-02,
    -1.001646376698259733e+00, -7.943731153661767186e-01, -5.562339701141498782e-01, -5.601183152598179227e-01,
    -1.058841849672694513e-01, -1.066119273812950574e+00, -3.510642280974009960e-02, -8.090653127939436695e-01,
    -5.379953800367767713e-02, -1.001646376698259733e+00, -7.943731153661767186e-01, -5.126595885009723741e-01,
    -5.803243432976363803e-01, -1.403914625722782750e-01, -1.065213991388674453e+00, -3.627346980774308338e-02,
    -7.990240146627038964e-01, -6.529667552350866544e-02, -1.049608292309140989e+00, -7.233938020841360617e-01,
    -4.750954664206468725e-01, -5.909084532222079744e-01, -1.725189279286657995e-01, -1.063478866742145090e+00,
    -3.907438260295022919e-02, -7.885210476518668132e-01, -7.679381304333966762e-02, -1.069592423813674698e+00,
    -6.611504042829619010e-01, -4.375313443403214264e-01, -5.707024251843895168e-01, -1.713290218043551638e-01,
    -1.060989340075385368e+00, -4.327575179576094444e-02, -7.776141203713822225e-01, -7.679381304333966762e-02,
    -1.069592423813674698e+00, -6.611504042829619010e-01, -3.999672222599959803e-01, -5.351013281653760334e-01,
    -1.356318380750356767e-01, -1.058198052600533901e+00, -4.701030218937047450e-02, -7.669380275306961758e-01,
};

// There is also another example that shows how to dynamically load
// inputs from system to esp32 for end to end online testing.
// Check if you people need that.

void loop() {

    if (!fp32MLP.predict(inputs).isOk()) {
        Serial.println(fp32MLP.exception.toString());
        return;
    }

    Serial.print("expected class 19, predicted class ");
    Serial.println(fp32MLP.classification);

    // Print free heap memory
    Serial.print("Free heap memory: ");
    Serial.print(esp_get_free_heap_size());
    Serial.println(" bytes");
    Serial.println("====================================================================");
    delay(1000);
}
