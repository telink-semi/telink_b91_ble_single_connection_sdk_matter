/********************************************************************************************************
 * @file	static_modes_fixed_arm_ne10.h
 *
 * @brief	This is the header file for B91
 *
 * @author	Ble Group
 * @date	2019
 *
 * @par     Copyright (c) 2019, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *          
 *          Redistribution and use in source and binary forms, with or without
 *          modification, are permitted provided that the following conditions are met:
 *          
 *              1. Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *          
 *              2. Unless for usage inside a TELINK integrated circuit, redistributions 
 *              in binary form must reproduce the above copyright notice, this list of 
 *              conditions and the following disclaimer in the documentation and/or other
 *              materials provided with the distribution.
 *          
 *              3. Neither the name of TELINK, nor the names of its contributors may be 
 *              used to endorse or promote products derived from this software without 
 *              specific prior written permission.
 *          
 *              4. This software, with or without modification, must only be used with a
 *              TELINK integrated circuit. All other usages are subject to written permission
 *              from TELINK and different commercial license may apply.
 *
 *              5. Licensee shall be solely responsible for any claim to the extent arising out of or 
 *              relating to such deletion(s), modification(s) or alteration(s).
 *         
 *          THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *          ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *          WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *          DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 *          DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *          ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *          SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *         
 *******************************************************************************************************/
/* The contents of this file was automatically generated by
 * dump_mode_arm_ne10.c with arguments: 48000 960
 * It contains static definitions for some pre-defined modes. */
#include <NE10_types.h>

#ifndef NE10_FFT_PARAMS48000_960
#define NE10_FFT_PARAMS48000_960
static const ne10_int32_t ne10_factors_480[64] = {
4, 40, 4, 30, 2, 15, 5, 3, 3, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, };
static const ne10_int32_t ne10_factors_240[64] = {
3, 20, 4, 15, 5, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, };
static const ne10_int32_t ne10_factors_120[64] = {
3, 10, 2, 15, 5, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, };
static const ne10_int32_t ne10_factors_60[64] = {
2, 5, 5, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, };
static const ne10_fft_cpx_int32_t ne10_twiddles_480[480] = {
{0,0}, {2147483647,0}, {2147483647,0},
{2147483647,0}, {1961823921,-873460313}, {1436946998,-1595891394},
{2147483647,0}, {1436946998,-1595891394}, {-224473265,-2135719496},
{2147483647,0}, {663608871,-2042378339}, {-1737350854,-1262259096},
{2147483647,0}, {-224473265,-2135719496}, {-2100555935,446487152},
{2147483647,0}, {2100555974,-446486968}, {1961823921,-873460313},
{1737350743,-1262259248}, {1436946998,-1595891394}, {1073741769,-1859775424},
{663608871,-2042378339}, {224473078,-2135719516}, {-224473265,-2135719496},
{-663609049,-2042378281}, {-1073741932,-1859775330}, {-1436947137,-1595891268},
{-1737350854,-1262259096}, {-1961823997,-873460141}, {-2100556013,-446486785},
{2147483647,0}, {2144540595,-112390613}, {2135719506,-224473172},
{2121044558,-335940465}, {2100555974,-446486968}, {2074309912,-555809682},
{2042378310,-663608960}, {2004848691,-769589332}, {1961823921,-873460313},
{1913421927,-974937199}, {1859775377,-1073741851}, {1801031311,-1169603450},
{1737350743,-1262259248}, {1668908218,-1351455280}, {1595891331,-1436947067},
{1518500216,-1518500282}, {1436946998,-1595891394}, {1351455207,-1668908277},
{1262259172,-1737350799}, {1169603371,-1801031362}, {1073741769,-1859775424},
{974937230,-1913421912}, {873460227,-1961823959}, {769589125,-2004848771},
{663608871,-2042378339}, {555809715,-2074309903}, {446486876,-2100555994},
{335940246,-2121044593}, {224473078,-2135719516}, {112390647,-2144540593},
{2147483647,0}, {2135719506,-224473172}, {2100555974,-446486968},
{2042378310,-663608960}, {1961823921,-873460313}, {1859775377,-1073741851},
{1737350743,-1262259248}, {1595891331,-1436947067}, {1436946998,-1595891394},
{1262259172,-1737350799}, {1073741769,-1859775424}, {873460227,-1961823959},
{663608871,-2042378339}, {446486876,-2100555994}, {224473078,-2135719516},
{-94,-2147483647}, {-224473265,-2135719496}, {-446487060,-2100555955},
{-663609049,-2042378281}, {-873460398,-1961823883}, {-1073741932,-1859775330},
{-1262259116,-1737350839}, {-1436947137,-1595891268}, {-1595891628,-1436946738},
{-1737350854,-1262259096}, {-1859775343,-1073741910}, {-1961823997,-873460141},
{-2042378447,-663608538}, {-2100556013,-446486785}, {-2135719499,-224473240},
{2147483647,0}, {2121044558,-335940465}, {2042378310,-663608960},
{1913421927,-974937199}, {1737350743,-1262259248}, {1518500216,-1518500282},
{1262259172,-1737350799}, {974937230,-1913421912}, {663608871,-2042378339},
{335940246,-2121044593}, {-94,-2147483647}, {-335940431,-2121044564},
{-663609049,-2042378281}, {-974937397,-1913421827}, {-1262259116,-1737350839},
{-1518500258,-1518500240}, {-1737350854,-1262259096}, {-1913422071,-974936918},
{-2042378447,-663608538}, {-2121044568,-335940406}, {-2147483647,188},
{-2121044509,335940777}, {-2042378331,663608895}, {-1913421900,974937252},
{-1737350633,1262259400}, {-1518499993,1518500506}, {-1262258813,1737351059},
{-974936606,1913422229}, {-663609179,2042378239}, {-335940566,2121044542},
{2147483647,0}, {2147299667,-28109693}, {2146747758,-56214570},
{2145828015,-84309815}, {2144540595,-112390613}, {2142885719,-140452154},
{2140863671,-168489630}, {2138474797,-196498235}, {2135719506,-224473172},
{2132598271,-252409646}, {2129111626,-280302871}, {2125260168,-308148068},
{2121044558,-335940465}, {2116465518,-363675300}, {2111523833,-391347822},
{2106220349,-418953288}, {2100555974,-446486968}, {2094531681,-473944146},
{2088148500,-501320115}, {2081407525,-528610186}, {2074309912,-555809682},
{2066856885,-582913912}, {2059049696,-609918325}, {2050889698,-636818231},
{2042378310,-663608960}, {2033516972,-690285983}, {2024307180,-716844791},
{2014750533,-743280770}, {2004848691,-769589332}, {1994603329,-795766029},
{1984016179,-821806435}, {1973089077,-847706028}, {1961823921,-873460313},
{1950222618,-899064934}, {1938287127,-924515564}, {1926019520,-949807783},
{1913421927,-974937199}, {1900496481,-999899565}, {1887245364,-1024690661},
{1873670877,-1049306180}, {1859775377,-1073741851}, {1845561215,-1097993541},
{1831030826,-1122057097}, {1816186632,-1145928502}, {1801031311,-1169603450},
{1785567394,-1193077993}, {1769797456,-1216348214}, {1753724345,-1239409914},
{1737350743,-1262259248}, {1720679456,-1284892300}, {1703713340,-1307305194},
{1686455222,-1329494189}, {1668908218,-1351455280}, {1651075255,-1373184807},
{1632959307,-1394679144}, {1614563642,-1415934412}, {1595891331,-1436947067},
{1576945572,-1457713510}, {1557729613,-1478230181}, {1538246655,-1498493658},
{1518500216,-1518500282}, {1498493590,-1538246721}, {1478230113,-1557729677},
{1457713441,-1576945636}, {1436946998,-1595891394}, {1415934341,-1614563704},
{1394679073,-1632959368}, {1373184735,-1651075315}, {1351455207,-1668908277},
{1329494115,-1686455280}, {1307305120,-1703713397}, {1284892225,-1720679512},
{1262259172,-1737350799}, {1239409837,-1753724400}, {1216348136,-1769797510},
{1193077915,-1785567446}, {1169603371,-1801031362}, {1145928423,-1816186682},
{1122057017,-1831030875}, {1097993571,-1845561197}, {1073741769,-1859775424},
{1049305987,-1873670985}, {1024690635,-1887245378}, {999899482,-1900496524},
{974937230,-1913421912}, {949807699,-1926019561}, {924515422,-1938287195},
{899064965,-1950222603}, {873460227,-1961823959}, {847705824,-1973089164},
{821806407,-1984016190}, {795765941,-1994603364}, {769589125,-2004848771},
{743280682,-2014750566}, {716844642,-2024307233}, {690286016,-2033516961},
{663608871,-2042378339}, {636818019,-2050889764}, {609918296,-2059049705},
{582913822,-2066856911}, {555809715,-2074309903}, {528610126,-2081407540},
{501319962,-2088148536}, {473944148,-2094531680}, {446486876,-2100555994},
{418953102,-2106220386}, {391347792,-2111523838}, {363675176,-2116465540},
{335940246,-2121044593}, {308148006,-2125260177}, {280302715,-2129111646},
{252409648,-2132598271}, {224473078,-2135719516}, {196498046,-2138474814},
{168489600,-2140863674}, {140452029,-2142885728}, {112390647,-2144540593},
{84309753,-2145828017}, {56214412,-2146747762}, {28109695,-2147299667},
{2147483647,0}, {2146747758,-56214570}, {2144540595,-112390613},
{2140863671,-168489630}, {2135719506,-224473172}, {2129111626,-280302871},
{2121044558,-335940465}, {2111523833,-391347822}, {2100555974,-446486968},
{2088148500,-501320115}, {2074309912,-555809682}, {2059049696,-609918325},
{2042378310,-663608960}, {2024307180,-716844791}, {2004848691,-769589332},
{1984016179,-821806435}, {1961823921,-873460313}, {1938287127,-924515564},
{1913421927,-974937199}, {1887245364,-1024690661}, {1859775377,-1073741851},
{1831030826,-1122057097}, {1801031311,-1169603450}, {1769797456,-1216348214},
{1737350743,-1262259248}, {1703713340,-1307305194}, {1668908218,-1351455280},
{1632959307,-1394679144}, {1595891331,-1436947067}, {1557729613,-1478230181},
{1518500216,-1518500282}, {1478230113,-1557729677}, {1436946998,-1595891394},
{1394679073,-1632959368}, {1351455207,-1668908277}, {1307305120,-1703713397},
{1262259172,-1737350799}, {1216348136,-1769797510}, {1169603371,-1801031362},
{1122057017,-1831030875}, {1073741769,-1859775424}, {1024690635,-1887245378},
{974937230,-1913421912}, {924515422,-1938287195}, {873460227,-1961823959},
{821806407,-1984016190}, {769589125,-2004848771}, {716844642,-2024307233},
{663608871,-2042378339}, {609918296,-2059049705}, {555809715,-2074309903},
{501319962,-2088148536}, {446486876,-2100555994}, {391347792,-2111523838},
{335940246,-2121044593}, {280302715,-2129111646}, {224473078,-2135719516},
{168489600,-2140863674}, {112390647,-2144540593}, {56214412,-2146747762},
{-94,-2147483647}, {-56214600,-2146747757}, {-112390835,-2144540584},
{-168489787,-2140863659}, {-224473265,-2135719496}, {-280302901,-2129111622},
{-335940431,-2121044564}, {-391347977,-2111523804}, {-446487060,-2100555955},
{-501320144,-2088148493}, {-555809896,-2074309855}, {-609918476,-2059049651},
{-663609049,-2042378281}, {-716844819,-2024307170}, {-769589300,-2004848703},
{-821806581,-1984016118}, {-873460398,-1961823883}, {-924515591,-1938287114},
{-974937397,-1913421827}, {-1024690575,-1887245411}, {-1073741932,-1859775330},
{-1122057395,-1831030643}, {-1169603421,-1801031330}, {-1216348291,-1769797403},
{-1262259116,-1737350839}, {-1307305268,-1703713283}, {-1351455453,-1668908078},
{-1394679021,-1632959413}, {-1436947137,-1595891268}, {-1478230435,-1557729372},
{-1518500258,-1518500240}, {-1557729742,-1478230045}, {-1595891628,-1436946738},
{-1632959429,-1394679001}, {-1668908417,-1351455035}, {-1703713298,-1307305248},
{-1737350854,-1262259096}, {-1769797708,-1216347848}, {-1801031344,-1169603400},
{-1831030924,-1122056937}, {-1859775343,-1073741910}, {-1887245423,-1024690552},
{-1913422071,-974936918}, {-1938287125,-924515568}, {-1961823997,-873460141},
{-1984016324,-821806084}, {-2004848713,-769589276}, {-2024307264,-716844553},
{-2042378447,-663608538}, {-2059049731,-609918206}, {-2074309994,-555809377},
{-2088148499,-501320119}, {-2100556013,-446486785}, {-2111523902,-391347448},
{-2121044568,-335940406}, {-2129111659,-280302621}, {-2135719499,-224473240},
{-2140863681,-168489506}, {-2144540612,-112390298}, {-2146747758,-56214574},
{2147483647,0}, {2145828015,-84309815}, {2140863671,-168489630},
{2132598271,-252409646}, {2121044558,-335940465}, {2106220349,-418953288},
{2088148500,-501320115}, {2066856885,-582913912}, {2042378310,-663608960},
{2014750533,-743280770}, {1984016179,-821806435}, {1950222618,-899064934},
{1913421927,-974937199}, {1873670877,-1049306180}, {1831030826,-1122057097},
{1785567394,-1193077993}, {1737350743,-1262259248}, {1686455222,-1329494189},
{1632959307,-1394679144}, {1576945572,-1457713510}, {1518500216,-1518500282},
{1457713441,-1576945636}, {1394679073,-1632959368}, {1329494115,-1686455280},
{1262259172,-1737350799}, {1193077915,-1785567446}, {1122057017,-1831030875},
{1049305987,-1873670985}, {974937230,-1913421912}, {899064965,-1950222603},
{821806407,-1984016190}, {743280682,-2014750566}, {663608871,-2042378339},
{582913822,-2066856911}, {501319962,-2088148536}, {418953102,-2106220386},
{335940246,-2121044593}, {252409648,-2132598271}, {168489600,-2140863674},
{84309753,-2145828017}, {-94,-2147483647}, {-84309940,-2145828010},
{-168489787,-2140863659}, {-252409834,-2132598249}, {-335940431,-2121044564},
{-418953286,-2106220349}, {-501320144,-2088148493}, {-582914003,-2066856860},
{-663609049,-2042378281}, {-743280858,-2014750501}, {-821806581,-1984016118},
{-899065136,-1950222525}, {-974937397,-1913421827}, {-1049306374,-1873670768},
{-1122057395,-1831030643}, {-1193078284,-1785567199}, {-1262259116,-1737350839},
{-1329494061,-1686455323}, {-1394679021,-1632959413}, {-1457713485,-1576945595},
{-1518500258,-1518500240}, {-1576945613,-1457713466}, {-1632959429,-1394679001},
{-1686455338,-1329494041}, {-1737350854,-1262259096}, {-1785567498,-1193077837},
{-1831030924,-1122056937}, {-1873671031,-1049305905}, {-1913422071,-974936918},
{-1950222750,-899064648}, {-1984016324,-821806084}, {-2014750687,-743280354},
{-2042378447,-663608538}, {-2066856867,-582913978}, {-2088148499,-501320119},
{-2106220354,-418953261}, {-2121044568,-335940406}, {-2132598282,-252409555},
{-2140863681,-168489506}, {-2145828021,-84309659}, {-2147483647,188},
{-2145828006,84310034}, {-2140863651,168489881}, {-2132598237,252409928},
{-2121044509,335940777}, {-2106220281,418953629}, {-2088148411,501320484},
{-2066856765,582914339}, {-2042378331,663608895}, {-2014750557,743280706},
{-1984016181,821806431}, {-1950222593,899064989}, {-1913421900,974937252},
{-1873670848,1049306232}, {-1831030728,1122057257}, {-1785567289,1193078149},
{-1737350633,1262259400}, {-1686455106,1329494336}, {-1632959185,1394679287},
{-1576945358,1457713742}, {-1518499993,1518500506}, {-1457713209,1576945850},
{-1394678735,1632959656}, {-1329493766,1686455555}, {-1262258813,1737351059},
{-1193077546,1785567692}, {-1122056638,1831031107}, {-1049305599,1873671202},
{-974936606,1913422229}, {-899064330,1950222896}, {-821805761,1984016458},
{-743280025,2014750808}, {-663609179,2042378239}, {-582914134,2066856823},
{-501320277,2088148461}, {-418953420,2106220322}, {-335940566,2121044542},
{-252409716,2132598263}, {-168489668,2140863668}, {-84309821,2145828015},
};
static const ne10_fft_cpx_int32_t ne10_twiddles_240[240] = {
{0,0}, {2147483647,0}, {2147483647,0},
{2147483647,0}, {1961823921,-873460313}, {1436946998,-1595891394},
{2147483647,0}, {1436946998,-1595891394}, {-224473265,-2135719496},
{2147483647,0}, {663608871,-2042378339}, {-1737350854,-1262259096},
{2147483647,0}, {-224473265,-2135719496}, {-2100555935,446487152},
{2147483647,0}, {2135719506,-224473172}, {2100555974,-446486968},
{2042378310,-663608960}, {1961823921,-873460313}, {1859775377,-1073741851},
{1737350743,-1262259248}, {1595891331,-1436947067}, {1436946998,-1595891394},
{1262259172,-1737350799}, {1073741769,-1859775424}, {873460227,-1961823959},
{663608871,-2042378339}, {446486876,-2100555994}, {224473078,-2135719516},
{2147483647,0}, {2100555974,-446486968}, {1961823921,-873460313},
{1737350743,-1262259248}, {1436946998,-1595891394}, {1073741769,-1859775424},
{663608871,-2042378339}, {224473078,-2135719516}, {-224473265,-2135719496},
{-663609049,-2042378281}, {-1073741932,-1859775330}, {-1436947137,-1595891268},
{-1737350854,-1262259096}, {-1961823997,-873460141}, {-2100556013,-446486785},
{2147483647,0}, {2042378310,-663608960}, {1737350743,-1262259248},
{1262259172,-1737350799}, {663608871,-2042378339}, {-94,-2147483647},
{-663609049,-2042378281}, {-1262259116,-1737350839}, {-1737350854,-1262259096},
{-2042378447,-663608538}, {-2147483647,188}, {-2042378331,663608895},
{-1737350633,1262259400}, {-1262258813,1737351059}, {-663609179,2042378239},
{2147483647,0}, {2146747758,-56214570}, {2144540595,-112390613},
{2140863671,-168489630}, {2135719506,-224473172}, {2129111626,-280302871},
{2121044558,-335940465}, {2111523833,-391347822}, {2100555974,-446486968},
{2088148500,-501320115}, {2074309912,-555809682}, {2059049696,-609918325},
{2042378310,-663608960}, {2024307180,-716844791}, {2004848691,-769589332},
{1984016179,-821806435}, {1961823921,-873460313}, {1938287127,-924515564},
{1913421927,-974937199}, {1887245364,-1024690661}, {1859775377,-1073741851},
{1831030826,-1122057097}, {1801031311,-1169603450}, {1769797456,-1216348214},
{1737350743,-1262259248}, {1703713340,-1307305194}, {1668908218,-1351455280},
{1632959307,-1394679144}, {1595891331,-1436947067}, {1557729613,-1478230181},
{1518500216,-1518500282}, {1478230113,-1557729677}, {1436946998,-1595891394},
{1394679073,-1632959368}, {1351455207,-1668908277}, {1307305120,-1703713397},
{1262259172,-1737350799}, {1216348136,-1769797510}, {1169603371,-1801031362},
{1122057017,-1831030875}, {1073741769,-1859775424}, {1024690635,-1887245378},
{974937230,-1913421912}, {924515422,-1938287195}, {873460227,-1961823959},
{821806407,-1984016190}, {769589125,-2004848771}, {716844642,-2024307233},
{663608871,-2042378339}, {609918296,-2059049705}, {555809715,-2074309903},
{501319962,-2088148536}, {446486876,-2100555994}, {391347792,-2111523838},
{335940246,-2121044593}, {280302715,-2129111646}, {224473078,-2135719516},
{168489600,-2140863674}, {112390647,-2144540593}, {56214412,-2146747762},
{2147483647,0}, {2144540595,-112390613}, {2135719506,-224473172},
{2121044558,-335940465}, {2100555974,-446486968}, {2074309912,-555809682},
{2042378310,-663608960}, {2004848691,-769589332}, {1961823921,-873460313},
{1913421927,-974937199}, {1859775377,-1073741851}, {1801031311,-1169603450},
{1737350743,-1262259248}, {1668908218,-1351455280}, {1595891331,-1436947067},
{1518500216,-1518500282}, {1436946998,-1595891394}, {1351455207,-1668908277},
{1262259172,-1737350799}, {1169603371,-1801031362}, {1073741769,-1859775424},
{974937230,-1913421912}, {873460227,-1961823959}, {769589125,-2004848771},
{663608871,-2042378339}, {555809715,-2074309903}, {446486876,-2100555994},
{335940246,-2121044593}, {224473078,-2135719516}, {112390647,-2144540593},
{-94,-2147483647}, {-112390835,-2144540584}, {-224473265,-2135719496},
{-335940431,-2121044564}, {-446487060,-2100555955}, {-555809896,-2074309855},
{-663609049,-2042378281}, {-769589300,-2004848703}, {-873460398,-1961823883},
{-974937397,-1913421827}, {-1073741932,-1859775330}, {-1169603421,-1801031330},
{-1262259116,-1737350839}, {-1351455453,-1668908078}, {-1436947137,-1595891268},
{-1518500258,-1518500240}, {-1595891628,-1436946738}, {-1668908417,-1351455035},
{-1737350854,-1262259096}, {-1801031344,-1169603400}, {-1859775343,-1073741910},
{-1913422071,-974936918}, {-1961823997,-873460141}, {-2004848713,-769589276},
{-2042378447,-663608538}, {-2074309994,-555809377}, {-2100556013,-446486785},
{-2121044568,-335940406}, {-2135719499,-224473240}, {-2144540612,-112390298},
{2147483647,0}, {2140863671,-168489630}, {2121044558,-335940465},
{2088148500,-501320115}, {2042378310,-663608960}, {1984016179,-821806435},
{1913421927,-974937199}, {1831030826,-1122057097}, {1737350743,-1262259248},
{1632959307,-1394679144}, {1518500216,-1518500282}, {1394679073,-1632959368},
{1262259172,-1737350799}, {1122057017,-1831030875}, {974937230,-1913421912},
{821806407,-1984016190}, {663608871,-2042378339}, {501319962,-2088148536},
{335940246,-2121044593}, {168489600,-2140863674}, {-94,-2147483647},
{-168489787,-2140863659}, {-335940431,-2121044564}, {-501320144,-2088148493},
{-663609049,-2042378281}, {-821806581,-1984016118}, {-974937397,-1913421827},
{-1122057395,-1831030643}, {-1262259116,-1737350839}, {-1394679021,-1632959413},
{-1518500258,-1518500240}, {-1632959429,-1394679001}, {-1737350854,-1262259096},
{-1831030924,-1122056937}, {-1913422071,-974936918}, {-1984016324,-821806084},
{-2042378447,-663608538}, {-2088148499,-501320119}, {-2121044568,-335940406},
{-2140863681,-168489506}, {-2147483647,188}, {-2140863651,168489881},
{-2121044509,335940777}, {-2088148411,501320484}, {-2042378331,663608895},
{-1984016181,821806431}, {-1913421900,974937252}, {-1831030728,1122057257},
{-1737350633,1262259400}, {-1632959185,1394679287}, {-1518499993,1518500506},
{-1394678735,1632959656}, {-1262258813,1737351059}, {-1122056638,1831031107},
{-974936606,1913422229}, {-821805761,1984016458}, {-663609179,2042378239},
{-501320277,2088148461}, {-335940566,2121044542}, {-168489668,2140863668},
};
static const ne10_fft_cpx_int32_t ne10_twiddles_120[120] = {
{0,0}, {2147483647,0}, {2147483647,0},
{2147483647,0}, {1961823921,-873460313}, {1436946998,-1595891394},
{2147483647,0}, {1436946998,-1595891394}, {-224473265,-2135719496},
{2147483647,0}, {663608871,-2042378339}, {-1737350854,-1262259096},
{2147483647,0}, {-224473265,-2135719496}, {-2100555935,446487152},
{2147483647,0}, {2100555974,-446486968}, {1961823921,-873460313},
{1737350743,-1262259248}, {1436946998,-1595891394}, {1073741769,-1859775424},
{663608871,-2042378339}, {224473078,-2135719516}, {-224473265,-2135719496},
{-663609049,-2042378281}, {-1073741932,-1859775330}, {-1436947137,-1595891268},
{-1737350854,-1262259096}, {-1961823997,-873460141}, {-2100556013,-446486785},
{2147483647,0}, {2144540595,-112390613}, {2135719506,-224473172},
{2121044558,-335940465}, {2100555974,-446486968}, {2074309912,-555809682},
{2042378310,-663608960}, {2004848691,-769589332}, {1961823921,-873460313},
{1913421927,-974937199}, {1859775377,-1073741851}, {1801031311,-1169603450},
{1737350743,-1262259248}, {1668908218,-1351455280}, {1595891331,-1436947067},
{1518500216,-1518500282}, {1436946998,-1595891394}, {1351455207,-1668908277},
{1262259172,-1737350799}, {1169603371,-1801031362}, {1073741769,-1859775424},
{974937230,-1913421912}, {873460227,-1961823959}, {769589125,-2004848771},
{663608871,-2042378339}, {555809715,-2074309903}, {446486876,-2100555994},
{335940246,-2121044593}, {224473078,-2135719516}, {112390647,-2144540593},
{2147483647,0}, {2135719506,-224473172}, {2100555974,-446486968},
{2042378310,-663608960}, {1961823921,-873460313}, {1859775377,-1073741851},
{1737350743,-1262259248}, {1595891331,-1436947067}, {1436946998,-1595891394},
{1262259172,-1737350799}, {1073741769,-1859775424}, {873460227,-1961823959},
{663608871,-2042378339}, {446486876,-2100555994}, {224473078,-2135719516},
{-94,-2147483647}, {-224473265,-2135719496}, {-446487060,-2100555955},
{-663609049,-2042378281}, {-873460398,-1961823883}, {-1073741932,-1859775330},
{-1262259116,-1737350839}, {-1436947137,-1595891268}, {-1595891628,-1436946738},
{-1737350854,-1262259096}, {-1859775343,-1073741910}, {-1961823997,-873460141},
{-2042378447,-663608538}, {-2100556013,-446486785}, {-2135719499,-224473240},
{2147483647,0}, {2121044558,-335940465}, {2042378310,-663608960},
{1913421927,-974937199}, {1737350743,-1262259248}, {1518500216,-1518500282},
{1262259172,-1737350799}, {974937230,-1913421912}, {663608871,-2042378339},
{335940246,-2121044593}, {-94,-2147483647}, {-335940431,-2121044564},
{-663609049,-2042378281}, {-974937397,-1913421827}, {-1262259116,-1737350839},
{-1518500258,-1518500240}, {-1737350854,-1262259096}, {-1913422071,-974936918},
{-2042378447,-663608538}, {-2121044568,-335940406}, {-2147483647,188},
{-2121044509,335940777}, {-2042378331,663608895}, {-1913421900,974937252},
{-1737350633,1262259400}, {-1518499993,1518500506}, {-1262258813,1737351059},
{-974936606,1913422229}, {-663609179,2042378239}, {-335940566,2121044542},
};
static const ne10_fft_cpx_int32_t ne10_twiddles_60[60] = {
{0,0}, {2147483647,0}, {2147483647,0},
{2147483647,0}, {1961823921,-873460313}, {1436946998,-1595891394},
{2147483647,0}, {1436946998,-1595891394}, {-224473265,-2135719496},
{2147483647,0}, {663608871,-2042378339}, {-1737350854,-1262259096},
{2147483647,0}, {-224473265,-2135719496}, {-2100555935,446487152},
{2147483647,0}, {2135719506,-224473172}, {2100555974,-446486968},
{2042378310,-663608960}, {1961823921,-873460313}, {1859775377,-1073741851},
{1737350743,-1262259248}, {1595891331,-1436947067}, {1436946998,-1595891394},
{1262259172,-1737350799}, {1073741769,-1859775424}, {873460227,-1961823959},
{663608871,-2042378339}, {446486876,-2100555994}, {224473078,-2135719516},
{2147483647,0}, {2100555974,-446486968}, {1961823921,-873460313},
{1737350743,-1262259248}, {1436946998,-1595891394}, {1073741769,-1859775424},
{663608871,-2042378339}, {224473078,-2135719516}, {-224473265,-2135719496},
{-663609049,-2042378281}, {-1073741932,-1859775330}, {-1436947137,-1595891268},
{-1737350854,-1262259096}, {-1961823997,-873460141}, {-2100556013,-446486785},
{2147483647,0}, {2042378310,-663608960}, {1737350743,-1262259248},
{1262259172,-1737350799}, {663608871,-2042378339}, {-94,-2147483647},
{-663609049,-2042378281}, {-1262259116,-1737350839}, {-1737350854,-1262259096},
{-2042378447,-663608538}, {-2147483647,188}, {-2042378331,663608895},
{-1737350633,1262259400}, {-1262258813,1737351059}, {-663609179,2042378239},
};
static const ne10_fft_state_int32_t ne10_fft_state_int32_t_480 = {
120,
(ne10_int32_t *)ne10_factors_480,
(ne10_fft_cpx_int32_t *)ne10_twiddles_480,
NULL,
(ne10_fft_cpx_int32_t *)&ne10_twiddles_480[120],
};
static const arch_fft_state cfg_arch_480 = {
1,
(void *)&ne10_fft_state_int32_t_480,
};

static const ne10_fft_state_int32_t ne10_fft_state_int32_t_240 = {
60,
(ne10_int32_t *)ne10_factors_240,
(ne10_fft_cpx_int32_t *)ne10_twiddles_240,
NULL,
(ne10_fft_cpx_int32_t *)&ne10_twiddles_240[60],
};
static const arch_fft_state cfg_arch_240 = {
1,
(void *)&ne10_fft_state_int32_t_240,
};

static const ne10_fft_state_int32_t ne10_fft_state_int32_t_120 = {
30,
(ne10_int32_t *)ne10_factors_120,
(ne10_fft_cpx_int32_t *)ne10_twiddles_120,
NULL,
(ne10_fft_cpx_int32_t *)&ne10_twiddles_120[30],
};
static const arch_fft_state cfg_arch_120 = {
1,
(void *)&ne10_fft_state_int32_t_120,
};

static const ne10_fft_state_int32_t ne10_fft_state_int32_t_60 = {
15,
(ne10_int32_t *)ne10_factors_60,
(ne10_fft_cpx_int32_t *)ne10_twiddles_60,
NULL,
(ne10_fft_cpx_int32_t *)&ne10_twiddles_60[15],
};
static const arch_fft_state cfg_arch_60 = {
1,
(void *)&ne10_fft_state_int32_t_60,
};

#endif  /* end NE10_FFT_PARAMS48000_960 */
