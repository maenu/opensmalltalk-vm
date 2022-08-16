/* sqMain.c -- main entry point for the standalone Squeak VM
 *
 *   Copyright (C) 2016 by Ronie Salgado
 *   All rights reserved.
 *
 *   This file is part of Minimalistic Headless Squeak.
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 *   copy of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom the
 *   Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 *
 * Author: roniesalg@gmail.com
 */
#ifdef EMSCRIPTEN
#include <emscripten.h>
void EMSCRIPTEN_KEEPALIVE dumb000(void) {}
void EMSCRIPTEN_KEEPALIVE dumb001(void) {}
void EMSCRIPTEN_KEEPALIVE dumb002(void) {}
void EMSCRIPTEN_KEEPALIVE dumb003(void) {}
void EMSCRIPTEN_KEEPALIVE dumb004(void) {}
void EMSCRIPTEN_KEEPALIVE dumb005(void) {}
void EMSCRIPTEN_KEEPALIVE dumb006(void) {}
void EMSCRIPTEN_KEEPALIVE dumb007(void) {}
void EMSCRIPTEN_KEEPALIVE dumb008(void) {}
void EMSCRIPTEN_KEEPALIVE dumb009(void) {}
void EMSCRIPTEN_KEEPALIVE dumb010(void) {}
void EMSCRIPTEN_KEEPALIVE dumb011(void) {}
void EMSCRIPTEN_KEEPALIVE dumb012(void) {}
void EMSCRIPTEN_KEEPALIVE dumb013(void) {}
void EMSCRIPTEN_KEEPALIVE dumb014(void) {}
void EMSCRIPTEN_KEEPALIVE dumb015(void) {}
void EMSCRIPTEN_KEEPALIVE dumb016(void) {}
void EMSCRIPTEN_KEEPALIVE dumb017(void) {}
void EMSCRIPTEN_KEEPALIVE dumb018(void) {}
void EMSCRIPTEN_KEEPALIVE dumb019(void) {}
void EMSCRIPTEN_KEEPALIVE dumb020(void) {}
void EMSCRIPTEN_KEEPALIVE dumb021(void) {}
void EMSCRIPTEN_KEEPALIVE dumb022(void) {}
void EMSCRIPTEN_KEEPALIVE dumb023(void) {}
void EMSCRIPTEN_KEEPALIVE dumb024(void) {}
void EMSCRIPTEN_KEEPALIVE dumb025(void) {}
void EMSCRIPTEN_KEEPALIVE dumb026(void) {}
void EMSCRIPTEN_KEEPALIVE dumb027(void) {}
void EMSCRIPTEN_KEEPALIVE dumb028(void) {}
void EMSCRIPTEN_KEEPALIVE dumb029(void) {}
void EMSCRIPTEN_KEEPALIVE dumb030(void) {}
void EMSCRIPTEN_KEEPALIVE dumb031(void) {}
void EMSCRIPTEN_KEEPALIVE dumb032(void) {}
void EMSCRIPTEN_KEEPALIVE dumb033(void) {}
void EMSCRIPTEN_KEEPALIVE dumb034(void) {}
void EMSCRIPTEN_KEEPALIVE dumb035(void) {}
void EMSCRIPTEN_KEEPALIVE dumb036(void) {}
void EMSCRIPTEN_KEEPALIVE dumb037(void) {}
void EMSCRIPTEN_KEEPALIVE dumb038(void) {}
void EMSCRIPTEN_KEEPALIVE dumb039(void) {}
void EMSCRIPTEN_KEEPALIVE dumb040(void) {}
void EMSCRIPTEN_KEEPALIVE dumb041(void) {}
void EMSCRIPTEN_KEEPALIVE dumb042(void) {}
void EMSCRIPTEN_KEEPALIVE dumb043(void) {}
void EMSCRIPTEN_KEEPALIVE dumb044(void) {}
void EMSCRIPTEN_KEEPALIVE dumb045(void) {}
void EMSCRIPTEN_KEEPALIVE dumb046(void) {}
void EMSCRIPTEN_KEEPALIVE dumb047(void) {}
void EMSCRIPTEN_KEEPALIVE dumb048(void) {}
void EMSCRIPTEN_KEEPALIVE dumb049(void) {}
void EMSCRIPTEN_KEEPALIVE dumb050(void) {}
void EMSCRIPTEN_KEEPALIVE dumb051(void) {}
void EMSCRIPTEN_KEEPALIVE dumb052(void) {}
void EMSCRIPTEN_KEEPALIVE dumb053(void) {}
void EMSCRIPTEN_KEEPALIVE dumb054(void) {}
void EMSCRIPTEN_KEEPALIVE dumb055(void) {}
void EMSCRIPTEN_KEEPALIVE dumb056(void) {}
void EMSCRIPTEN_KEEPALIVE dumb057(void) {}
void EMSCRIPTEN_KEEPALIVE dumb058(void) {}
void EMSCRIPTEN_KEEPALIVE dumb059(void) {}
void EMSCRIPTEN_KEEPALIVE dumb060(void) {}
void EMSCRIPTEN_KEEPALIVE dumb061(void) {}
void EMSCRIPTEN_KEEPALIVE dumb062(void) {}
void EMSCRIPTEN_KEEPALIVE dumb063(void) {}
void EMSCRIPTEN_KEEPALIVE dumb064(void) {}
void EMSCRIPTEN_KEEPALIVE dumb065(void) {}
void EMSCRIPTEN_KEEPALIVE dumb066(void) {}
void EMSCRIPTEN_KEEPALIVE dumb067(void) {}
void EMSCRIPTEN_KEEPALIVE dumb068(void) {}
void EMSCRIPTEN_KEEPALIVE dumb069(void) {}
void EMSCRIPTEN_KEEPALIVE dumb070(void) {}
void EMSCRIPTEN_KEEPALIVE dumb071(void) {}
void EMSCRIPTEN_KEEPALIVE dumb072(void) {}
void EMSCRIPTEN_KEEPALIVE dumb073(void) {}
void EMSCRIPTEN_KEEPALIVE dumb074(void) {}
void EMSCRIPTEN_KEEPALIVE dumb075(void) {}
void EMSCRIPTEN_KEEPALIVE dumb076(void) {}
void EMSCRIPTEN_KEEPALIVE dumb077(void) {}
void EMSCRIPTEN_KEEPALIVE dumb078(void) {}
void EMSCRIPTEN_KEEPALIVE dumb079(void) {}
void EMSCRIPTEN_KEEPALIVE dumb080(void) {}
void EMSCRIPTEN_KEEPALIVE dumb081(void) {}
void EMSCRIPTEN_KEEPALIVE dumb082(void) {}
void EMSCRIPTEN_KEEPALIVE dumb083(void) {}
void EMSCRIPTEN_KEEPALIVE dumb084(void) {}
void EMSCRIPTEN_KEEPALIVE dumb085(void) {}
void EMSCRIPTEN_KEEPALIVE dumb086(void) {}
void EMSCRIPTEN_KEEPALIVE dumb087(void) {}
void EMSCRIPTEN_KEEPALIVE dumb088(void) {}
void EMSCRIPTEN_KEEPALIVE dumb089(void) {}
void EMSCRIPTEN_KEEPALIVE dumb090(void) {}
void EMSCRIPTEN_KEEPALIVE dumb091(void) {}
void EMSCRIPTEN_KEEPALIVE dumb092(void) {}
void EMSCRIPTEN_KEEPALIVE dumb093(void) {}
void EMSCRIPTEN_KEEPALIVE dumb094(void) {}
void EMSCRIPTEN_KEEPALIVE dumb095(void) {}
void EMSCRIPTEN_KEEPALIVE dumb096(void) {}
void EMSCRIPTEN_KEEPALIVE dumb097(void) {}
void EMSCRIPTEN_KEEPALIVE dumb098(void) {}
void EMSCRIPTEN_KEEPALIVE dumb099(void) {}
void EMSCRIPTEN_KEEPALIVE dumb100(void) {}
void EMSCRIPTEN_KEEPALIVE dumb101(void) {}
void EMSCRIPTEN_KEEPALIVE dumb102(void) {}
void EMSCRIPTEN_KEEPALIVE dumb103(void) {}
void EMSCRIPTEN_KEEPALIVE dumb104(void) {}
void EMSCRIPTEN_KEEPALIVE dumb105(void) {}
void EMSCRIPTEN_KEEPALIVE dumb106(void) {}
void EMSCRIPTEN_KEEPALIVE dumb107(void) {}
void EMSCRIPTEN_KEEPALIVE dumb108(void) {}
void EMSCRIPTEN_KEEPALIVE dumb109(void) {}
void EMSCRIPTEN_KEEPALIVE dumb110(void) {}
void EMSCRIPTEN_KEEPALIVE dumb111(void) {}
void EMSCRIPTEN_KEEPALIVE dumb112(void) {}
void EMSCRIPTEN_KEEPALIVE dumb113(void) {}
void EMSCRIPTEN_KEEPALIVE dumb114(void) {}
void EMSCRIPTEN_KEEPALIVE dumb115(void) {}
void EMSCRIPTEN_KEEPALIVE dumb116(void) {}
void EMSCRIPTEN_KEEPALIVE dumb117(void) {}
void EMSCRIPTEN_KEEPALIVE dumb118(void) {}
void EMSCRIPTEN_KEEPALIVE dumb119(void) {}
void EMSCRIPTEN_KEEPALIVE dumb120(void) {}
void EMSCRIPTEN_KEEPALIVE dumb121(void) {}
void EMSCRIPTEN_KEEPALIVE dumb122(void) {}
void EMSCRIPTEN_KEEPALIVE dumb123(void) {}
void EMSCRIPTEN_KEEPALIVE dumb124(void) {}
void EMSCRIPTEN_KEEPALIVE dumb125(void) {}
void EMSCRIPTEN_KEEPALIVE dumb126(void) {}
void EMSCRIPTEN_KEEPALIVE dumb127(void) {}
void EMSCRIPTEN_KEEPALIVE dumb128(void) {}
void EMSCRIPTEN_KEEPALIVE dumb129(void) {}
void EMSCRIPTEN_KEEPALIVE dumb130(void) {}
void EMSCRIPTEN_KEEPALIVE dumb131(void) {}
void EMSCRIPTEN_KEEPALIVE dumb132(void) {}
void EMSCRIPTEN_KEEPALIVE dumb133(void) {}
void EMSCRIPTEN_KEEPALIVE dumb134(void) {}
void EMSCRIPTEN_KEEPALIVE dumb135(void) {}
void EMSCRIPTEN_KEEPALIVE dumb136(void) {}
void EMSCRIPTEN_KEEPALIVE dumb137(void) {}
void EMSCRIPTEN_KEEPALIVE dumb138(void) {}
void EMSCRIPTEN_KEEPALIVE dumb139(void) {}
void EMSCRIPTEN_KEEPALIVE dumb140(void) {}
void EMSCRIPTEN_KEEPALIVE dumb141(void) {}
void EMSCRIPTEN_KEEPALIVE dumb142(void) {}
void EMSCRIPTEN_KEEPALIVE dumb143(void) {}
void EMSCRIPTEN_KEEPALIVE dumb144(void) {}
void EMSCRIPTEN_KEEPALIVE dumb145(void) {}
void EMSCRIPTEN_KEEPALIVE dumb146(void) {}
void EMSCRIPTEN_KEEPALIVE dumb147(void) {}
void EMSCRIPTEN_KEEPALIVE dumb148(void) {}
void EMSCRIPTEN_KEEPALIVE dumb149(void) {}
void EMSCRIPTEN_KEEPALIVE dumb150(void) {}
void EMSCRIPTEN_KEEPALIVE dumb151(void) {}
void EMSCRIPTEN_KEEPALIVE dumb152(void) {}
void EMSCRIPTEN_KEEPALIVE dumb153(void) {}
void EMSCRIPTEN_KEEPALIVE dumb154(void) {}
void EMSCRIPTEN_KEEPALIVE dumb155(void) {}
void EMSCRIPTEN_KEEPALIVE dumb156(void) {}
void EMSCRIPTEN_KEEPALIVE dumb157(void) {}
void EMSCRIPTEN_KEEPALIVE dumb158(void) {}
void EMSCRIPTEN_KEEPALIVE dumb159(void) {}
void EMSCRIPTEN_KEEPALIVE dumb160(void) {}
void EMSCRIPTEN_KEEPALIVE dumb161(void) {}
void EMSCRIPTEN_KEEPALIVE dumb162(void) {}
void EMSCRIPTEN_KEEPALIVE dumb163(void) {}
void EMSCRIPTEN_KEEPALIVE dumb164(void) {}
void EMSCRIPTEN_KEEPALIVE dumb165(void) {}
void EMSCRIPTEN_KEEPALIVE dumb166(void) {}
void EMSCRIPTEN_KEEPALIVE dumb167(void) {}
void EMSCRIPTEN_KEEPALIVE dumb168(void) {}
void EMSCRIPTEN_KEEPALIVE dumb169(void) {}
void EMSCRIPTEN_KEEPALIVE dumb170(void) {}
void EMSCRIPTEN_KEEPALIVE dumb171(void) {}
void EMSCRIPTEN_KEEPALIVE dumb172(void) {}
void EMSCRIPTEN_KEEPALIVE dumb173(void) {}
void EMSCRIPTEN_KEEPALIVE dumb174(void) {}
void EMSCRIPTEN_KEEPALIVE dumb175(void) {}
void EMSCRIPTEN_KEEPALIVE dumb176(void) {}
void EMSCRIPTEN_KEEPALIVE dumb177(void) {}
void EMSCRIPTEN_KEEPALIVE dumb178(void) {}
void EMSCRIPTEN_KEEPALIVE dumb179(void) {}
void EMSCRIPTEN_KEEPALIVE dumb180(void) {}
void EMSCRIPTEN_KEEPALIVE dumb181(void) {}
void EMSCRIPTEN_KEEPALIVE dumb182(void) {}
void EMSCRIPTEN_KEEPALIVE dumb183(void) {}
void EMSCRIPTEN_KEEPALIVE dumb184(void) {}
void EMSCRIPTEN_KEEPALIVE dumb185(void) {}
void EMSCRIPTEN_KEEPALIVE dumb186(void) {}
void EMSCRIPTEN_KEEPALIVE dumb187(void) {}
void EMSCRIPTEN_KEEPALIVE dumb188(void) {}
void EMSCRIPTEN_KEEPALIVE dumb189(void) {}
void EMSCRIPTEN_KEEPALIVE dumb190(void) {}
void EMSCRIPTEN_KEEPALIVE dumb191(void) {}
void EMSCRIPTEN_KEEPALIVE dumb192(void) {}
void EMSCRIPTEN_KEEPALIVE dumb193(void) {}
void EMSCRIPTEN_KEEPALIVE dumb194(void) {}
void EMSCRIPTEN_KEEPALIVE dumb195(void) {}
void EMSCRIPTEN_KEEPALIVE dumb196(void) {}
void EMSCRIPTEN_KEEPALIVE dumb197(void) {}
void EMSCRIPTEN_KEEPALIVE dumb198(void) {}
void EMSCRIPTEN_KEEPALIVE dumb199(void) {}
void EMSCRIPTEN_KEEPALIVE dumb200(void) {}
void EMSCRIPTEN_KEEPALIVE dumb201(void) {}
void EMSCRIPTEN_KEEPALIVE dumb202(void) {}
void EMSCRIPTEN_KEEPALIVE dumb203(void) {}
void EMSCRIPTEN_KEEPALIVE dumb204(void) {}
void EMSCRIPTEN_KEEPALIVE dumb205(void) {}
void EMSCRIPTEN_KEEPALIVE dumb206(void) {}
void EMSCRIPTEN_KEEPALIVE dumb207(void) {}
void EMSCRIPTEN_KEEPALIVE dumb208(void) {}
void EMSCRIPTEN_KEEPALIVE dumb209(void) {}
void EMSCRIPTEN_KEEPALIVE dumb210(void) {}
void EMSCRIPTEN_KEEPALIVE dumb211(void) {}
void EMSCRIPTEN_KEEPALIVE dumb212(void) {}
void EMSCRIPTEN_KEEPALIVE dumb213(void) {}
void EMSCRIPTEN_KEEPALIVE dumb214(void) {}
void EMSCRIPTEN_KEEPALIVE dumb215(void) {}
void EMSCRIPTEN_KEEPALIVE dumb216(void) {}
void EMSCRIPTEN_KEEPALIVE dumb217(void) {}
void EMSCRIPTEN_KEEPALIVE dumb218(void) {}
void EMSCRIPTEN_KEEPALIVE dumb219(void) {}
void EMSCRIPTEN_KEEPALIVE dumb220(void) {}
void EMSCRIPTEN_KEEPALIVE dumb221(void) {}
void EMSCRIPTEN_KEEPALIVE dumb222(void) {}
void EMSCRIPTEN_KEEPALIVE dumb223(void) {}
void EMSCRIPTEN_KEEPALIVE dumb224(void) {}
void EMSCRIPTEN_KEEPALIVE dumb225(void) {}
void EMSCRIPTEN_KEEPALIVE dumb226(void) {}
void EMSCRIPTEN_KEEPALIVE dumb227(void) {}
void EMSCRIPTEN_KEEPALIVE dumb228(void) {}
void EMSCRIPTEN_KEEPALIVE dumb229(void) {}
void EMSCRIPTEN_KEEPALIVE dumb230(void) {}
void EMSCRIPTEN_KEEPALIVE dumb231(void) {}
void EMSCRIPTEN_KEEPALIVE dumb232(void) {}
void EMSCRIPTEN_KEEPALIVE dumb233(void) {}
void EMSCRIPTEN_KEEPALIVE dumb234(void) {}
void EMSCRIPTEN_KEEPALIVE dumb235(void) {}
void EMSCRIPTEN_KEEPALIVE dumb236(void) {}
void EMSCRIPTEN_KEEPALIVE dumb237(void) {}
void EMSCRIPTEN_KEEPALIVE dumb238(void) {}
void EMSCRIPTEN_KEEPALIVE dumb239(void) {}
void EMSCRIPTEN_KEEPALIVE dumb240(void) {}
void EMSCRIPTEN_KEEPALIVE dumb241(void) {}
void EMSCRIPTEN_KEEPALIVE dumb242(void) {}
void EMSCRIPTEN_KEEPALIVE dumb243(void) {}
void EMSCRIPTEN_KEEPALIVE dumb244(void) {}
void EMSCRIPTEN_KEEPALIVE dumb245(void) {}
void EMSCRIPTEN_KEEPALIVE dumb246(void) {}
void EMSCRIPTEN_KEEPALIVE dumb247(void) {}
void EMSCRIPTEN_KEEPALIVE dumb248(void) {}
void EMSCRIPTEN_KEEPALIVE dumb249(void) {}
void EMSCRIPTEN_KEEPALIVE dumb250(void) {}
void EMSCRIPTEN_KEEPALIVE dumb251(void) {}
void EMSCRIPTEN_KEEPALIVE dumb252(void) {}
void EMSCRIPTEN_KEEPALIVE dumb253(void) {}
void EMSCRIPTEN_KEEPALIVE dumb254(void) {}
void EMSCRIPTEN_KEEPALIVE dumb255(void) {}
void EMSCRIPTEN_KEEPALIVE dumb256(void) {}
void EMSCRIPTEN_KEEPALIVE dumb257(void) {}
void EMSCRIPTEN_KEEPALIVE dumb258(void) {}
void EMSCRIPTEN_KEEPALIVE dumb259(void) {}
void EMSCRIPTEN_KEEPALIVE dumb260(void) {}
void EMSCRIPTEN_KEEPALIVE dumb261(void) {}
void EMSCRIPTEN_KEEPALIVE dumb262(void) {}
void EMSCRIPTEN_KEEPALIVE dumb263(void) {}
void EMSCRIPTEN_KEEPALIVE dumb264(void) {}
void EMSCRIPTEN_KEEPALIVE dumb265(void) {}
void EMSCRIPTEN_KEEPALIVE dumb266(void) {}
void EMSCRIPTEN_KEEPALIVE dumb267(void) {}
void EMSCRIPTEN_KEEPALIVE dumb268(void) {}
void EMSCRIPTEN_KEEPALIVE dumb269(void) {}
void EMSCRIPTEN_KEEPALIVE dumb270(void) {}
void EMSCRIPTEN_KEEPALIVE dumb271(void) {}
void EMSCRIPTEN_KEEPALIVE dumb272(void) {}
void EMSCRIPTEN_KEEPALIVE dumb273(void) {}
void EMSCRIPTEN_KEEPALIVE dumb274(void) {}
void EMSCRIPTEN_KEEPALIVE dumb275(void) {}
void EMSCRIPTEN_KEEPALIVE dumb276(void) {}
void EMSCRIPTEN_KEEPALIVE dumb277(void) {}
void EMSCRIPTEN_KEEPALIVE dumb278(void) {}
void EMSCRIPTEN_KEEPALIVE dumb279(void) {}
void EMSCRIPTEN_KEEPALIVE dumb280(void) {}
void EMSCRIPTEN_KEEPALIVE dumb281(void) {}
void EMSCRIPTEN_KEEPALIVE dumb282(void) {}
void EMSCRIPTEN_KEEPALIVE dumb283(void) {}
void EMSCRIPTEN_KEEPALIVE dumb284(void) {}
void EMSCRIPTEN_KEEPALIVE dumb285(void) {}
void EMSCRIPTEN_KEEPALIVE dumb286(void) {}
void EMSCRIPTEN_KEEPALIVE dumb287(void) {}
void EMSCRIPTEN_KEEPALIVE dumb288(void) {}
void EMSCRIPTEN_KEEPALIVE dumb289(void) {}
void EMSCRIPTEN_KEEPALIVE dumb290(void) {}
void EMSCRIPTEN_KEEPALIVE dumb291(void) {}
void EMSCRIPTEN_KEEPALIVE dumb292(void) {}
void EMSCRIPTEN_KEEPALIVE dumb293(void) {}
void EMSCRIPTEN_KEEPALIVE dumb294(void) {}
void EMSCRIPTEN_KEEPALIVE dumb295(void) {}
void EMSCRIPTEN_KEEPALIVE dumb296(void) {}
void EMSCRIPTEN_KEEPALIVE dumb297(void) {}
void EMSCRIPTEN_KEEPALIVE dumb298(void) {}
void EMSCRIPTEN_KEEPALIVE dumb299(void) {}
void EMSCRIPTEN_KEEPALIVE dumb300(void) {}
void EMSCRIPTEN_KEEPALIVE dumb301(void) {}
void EMSCRIPTEN_KEEPALIVE dumb302(void) {}
void EMSCRIPTEN_KEEPALIVE dumb303(void) {}
void EMSCRIPTEN_KEEPALIVE dumb304(void) {}
void EMSCRIPTEN_KEEPALIVE dumb305(void) {}
void EMSCRIPTEN_KEEPALIVE dumb306(void) {}
void EMSCRIPTEN_KEEPALIVE dumb307(void) {}
void EMSCRIPTEN_KEEPALIVE dumb308(void) {}
void EMSCRIPTEN_KEEPALIVE dumb309(void) {}
void EMSCRIPTEN_KEEPALIVE dumb310(void) {}
void EMSCRIPTEN_KEEPALIVE dumb311(void) {}
void EMSCRIPTEN_KEEPALIVE dumb312(void) {}
void EMSCRIPTEN_KEEPALIVE dumb313(void) {}
void EMSCRIPTEN_KEEPALIVE dumb314(void) {}
void EMSCRIPTEN_KEEPALIVE dumb315(void) {}
void EMSCRIPTEN_KEEPALIVE dumb316(void) {}
void EMSCRIPTEN_KEEPALIVE dumb317(void) {}
void EMSCRIPTEN_KEEPALIVE dumb318(void) {}
void EMSCRIPTEN_KEEPALIVE dumb319(void) {}
void EMSCRIPTEN_KEEPALIVE dumb320(void) {}
void EMSCRIPTEN_KEEPALIVE dumb321(void) {}
void EMSCRIPTEN_KEEPALIVE dumb322(void) {}
void EMSCRIPTEN_KEEPALIVE dumb323(void) {}
void EMSCRIPTEN_KEEPALIVE dumb324(void) {}
void EMSCRIPTEN_KEEPALIVE dumb325(void) {}
void EMSCRIPTEN_KEEPALIVE dumb326(void) {}
void EMSCRIPTEN_KEEPALIVE dumb327(void) {}
void EMSCRIPTEN_KEEPALIVE dumb328(void) {}
void EMSCRIPTEN_KEEPALIVE dumb329(void) {}
void EMSCRIPTEN_KEEPALIVE dumb330(void) {}
void EMSCRIPTEN_KEEPALIVE dumb331(void) {}
void EMSCRIPTEN_KEEPALIVE dumb332(void) {}
void EMSCRIPTEN_KEEPALIVE dumb333(void) {}
void EMSCRIPTEN_KEEPALIVE dumb334(void) {}
void EMSCRIPTEN_KEEPALIVE dumb335(void) {}
void EMSCRIPTEN_KEEPALIVE dumb336(void) {}
void EMSCRIPTEN_KEEPALIVE dumb337(void) {}
void EMSCRIPTEN_KEEPALIVE dumb338(void) {}
void EMSCRIPTEN_KEEPALIVE dumb339(void) {}
void EMSCRIPTEN_KEEPALIVE dumb340(void) {}
void EMSCRIPTEN_KEEPALIVE dumb341(void) {}
void EMSCRIPTEN_KEEPALIVE dumb342(void) {}
void EMSCRIPTEN_KEEPALIVE dumb343(void) {}
void EMSCRIPTEN_KEEPALIVE dumb344(void) {}
void EMSCRIPTEN_KEEPALIVE dumb345(void) {}
void EMSCRIPTEN_KEEPALIVE dumb346(void) {}
void EMSCRIPTEN_KEEPALIVE dumb347(void) {}
void EMSCRIPTEN_KEEPALIVE dumb348(void) {}
void EMSCRIPTEN_KEEPALIVE dumb349(void) {}
void EMSCRIPTEN_KEEPALIVE dumb350(void) {}
void EMSCRIPTEN_KEEPALIVE dumb351(void) {}
void EMSCRIPTEN_KEEPALIVE dumb352(void) {}
void EMSCRIPTEN_KEEPALIVE dumb353(void) {}
void EMSCRIPTEN_KEEPALIVE dumb354(void) {}
void EMSCRIPTEN_KEEPALIVE dumb355(void) {}
void EMSCRIPTEN_KEEPALIVE dumb356(void) {}
void EMSCRIPTEN_KEEPALIVE dumb357(void) {}
void EMSCRIPTEN_KEEPALIVE dumb358(void) {}
void EMSCRIPTEN_KEEPALIVE dumb359(void) {}
void EMSCRIPTEN_KEEPALIVE dumb360(void) {}
void EMSCRIPTEN_KEEPALIVE dumb361(void) {}
void EMSCRIPTEN_KEEPALIVE dumb362(void) {}
void EMSCRIPTEN_KEEPALIVE dumb363(void) {}
void EMSCRIPTEN_KEEPALIVE dumb364(void) {}
void EMSCRIPTEN_KEEPALIVE dumb365(void) {}
void EMSCRIPTEN_KEEPALIVE dumb366(void) {}
void EMSCRIPTEN_KEEPALIVE dumb367(void) {}
void EMSCRIPTEN_KEEPALIVE dumb368(void) {}
void EMSCRIPTEN_KEEPALIVE dumb369(void) {}
void EMSCRIPTEN_KEEPALIVE dumb370(void) {}
void EMSCRIPTEN_KEEPALIVE dumb371(void) {}
void EMSCRIPTEN_KEEPALIVE dumb372(void) {}
void EMSCRIPTEN_KEEPALIVE dumb373(void) {}
void EMSCRIPTEN_KEEPALIVE dumb374(void) {}
void EMSCRIPTEN_KEEPALIVE dumb375(void) {}
void EMSCRIPTEN_KEEPALIVE dumb376(void) {}
void EMSCRIPTEN_KEEPALIVE dumb377(void) {}
void EMSCRIPTEN_KEEPALIVE dumb378(void) {}
void EMSCRIPTEN_KEEPALIVE dumb379(void) {}
void EMSCRIPTEN_KEEPALIVE dumb380(void) {}
void EMSCRIPTEN_KEEPALIVE dumb381(void) {}
void EMSCRIPTEN_KEEPALIVE dumb382(void) {}
void EMSCRIPTEN_KEEPALIVE dumb383(void) {}
void EMSCRIPTEN_KEEPALIVE dumb384(void) {}
void EMSCRIPTEN_KEEPALIVE dumb385(void) {}
void EMSCRIPTEN_KEEPALIVE dumb386(void) {}
void EMSCRIPTEN_KEEPALIVE dumb387(void) {}
void EMSCRIPTEN_KEEPALIVE dumb388(void) {}
void EMSCRIPTEN_KEEPALIVE dumb389(void) {}
void EMSCRIPTEN_KEEPALIVE dumb390(void) {}
void EMSCRIPTEN_KEEPALIVE dumb391(void) {}
void EMSCRIPTEN_KEEPALIVE dumb392(void) {}
void EMSCRIPTEN_KEEPALIVE dumb393(void) {}
void EMSCRIPTEN_KEEPALIVE dumb394(void) {}
void EMSCRIPTEN_KEEPALIVE dumb395(void) {}
void EMSCRIPTEN_KEEPALIVE dumb396(void) {}
void EMSCRIPTEN_KEEPALIVE dumb397(void) {}
void EMSCRIPTEN_KEEPALIVE dumb398(void) {}
void EMSCRIPTEN_KEEPALIVE dumb399(void) {}
void EMSCRIPTEN_KEEPALIVE dumb400(void) {}
void EMSCRIPTEN_KEEPALIVE dumb401(void) {}
void EMSCRIPTEN_KEEPALIVE dumb402(void) {}
void EMSCRIPTEN_KEEPALIVE dumb403(void) {}
void EMSCRIPTEN_KEEPALIVE dumb404(void) {}
void EMSCRIPTEN_KEEPALIVE dumb405(void) {}
void EMSCRIPTEN_KEEPALIVE dumb406(void) {}
void EMSCRIPTEN_KEEPALIVE dumb407(void) {}
void EMSCRIPTEN_KEEPALIVE dumb408(void) {}
void EMSCRIPTEN_KEEPALIVE dumb409(void) {}
void EMSCRIPTEN_KEEPALIVE dumb410(void) {}
void EMSCRIPTEN_KEEPALIVE dumb411(void) {}
void EMSCRIPTEN_KEEPALIVE dumb412(void) {}
void EMSCRIPTEN_KEEPALIVE dumb413(void) {}
void EMSCRIPTEN_KEEPALIVE dumb414(void) {}
void EMSCRIPTEN_KEEPALIVE dumb415(void) {}
void EMSCRIPTEN_KEEPALIVE dumb416(void) {}
void EMSCRIPTEN_KEEPALIVE dumb417(void) {}
void EMSCRIPTEN_KEEPALIVE dumb418(void) {}
void EMSCRIPTEN_KEEPALIVE dumb419(void) {}
void EMSCRIPTEN_KEEPALIVE dumb420(void) {}
void EMSCRIPTEN_KEEPALIVE dumb421(void) {}
void EMSCRIPTEN_KEEPALIVE dumb422(void) {}
void EMSCRIPTEN_KEEPALIVE dumb423(void) {}
void EMSCRIPTEN_KEEPALIVE dumb424(void) {}
void EMSCRIPTEN_KEEPALIVE dumb425(void) {}
void EMSCRIPTEN_KEEPALIVE dumb426(void) {}
void EMSCRIPTEN_KEEPALIVE dumb427(void) {}
void EMSCRIPTEN_KEEPALIVE dumb428(void) {}
void EMSCRIPTEN_KEEPALIVE dumb429(void) {}
void EMSCRIPTEN_KEEPALIVE dumb430(void) {}
void EMSCRIPTEN_KEEPALIVE dumb431(void) {}
void EMSCRIPTEN_KEEPALIVE dumb432(void) {}
void EMSCRIPTEN_KEEPALIVE dumb433(void) {}
void EMSCRIPTEN_KEEPALIVE dumb434(void) {}
void EMSCRIPTEN_KEEPALIVE dumb435(void) {}
void EMSCRIPTEN_KEEPALIVE dumb436(void) {}
void EMSCRIPTEN_KEEPALIVE dumb437(void) {}
void EMSCRIPTEN_KEEPALIVE dumb438(void) {}
void EMSCRIPTEN_KEEPALIVE dumb439(void) {}
void EMSCRIPTEN_KEEPALIVE dumb440(void) {}
void EMSCRIPTEN_KEEPALIVE dumb441(void) {}
void EMSCRIPTEN_KEEPALIVE dumb442(void) {}
void EMSCRIPTEN_KEEPALIVE dumb443(void) {}
void EMSCRIPTEN_KEEPALIVE dumb444(void) {}
void EMSCRIPTEN_KEEPALIVE dumb445(void) {}
void EMSCRIPTEN_KEEPALIVE dumb446(void) {}
void EMSCRIPTEN_KEEPALIVE dumb447(void) {}
void EMSCRIPTEN_KEEPALIVE dumb448(void) {}
void EMSCRIPTEN_KEEPALIVE dumb449(void) {}
void EMSCRIPTEN_KEEPALIVE dumb450(void) {}
void EMSCRIPTEN_KEEPALIVE dumb451(void) {}
void EMSCRIPTEN_KEEPALIVE dumb452(void) {}
void EMSCRIPTEN_KEEPALIVE dumb453(void) {}
void EMSCRIPTEN_KEEPALIVE dumb454(void) {}
void EMSCRIPTEN_KEEPALIVE dumb455(void) {}
void EMSCRIPTEN_KEEPALIVE dumb456(void) {}
void EMSCRIPTEN_KEEPALIVE dumb457(void) {}
void EMSCRIPTEN_KEEPALIVE dumb458(void) {}
void EMSCRIPTEN_KEEPALIVE dumb459(void) {}
void EMSCRIPTEN_KEEPALIVE dumb460(void) {}
void EMSCRIPTEN_KEEPALIVE dumb461(void) {}
void EMSCRIPTEN_KEEPALIVE dumb462(void) {}
void EMSCRIPTEN_KEEPALIVE dumb463(void) {}
void EMSCRIPTEN_KEEPALIVE dumb464(void) {}
void EMSCRIPTEN_KEEPALIVE dumb465(void) {}
void EMSCRIPTEN_KEEPALIVE dumb466(void) {}
void EMSCRIPTEN_KEEPALIVE dumb467(void) {}
void EMSCRIPTEN_KEEPALIVE dumb468(void) {}
void EMSCRIPTEN_KEEPALIVE dumb469(void) {}
void EMSCRIPTEN_KEEPALIVE dumb470(void) {}
void EMSCRIPTEN_KEEPALIVE dumb471(void) {}
void EMSCRIPTEN_KEEPALIVE dumb472(void) {}
void EMSCRIPTEN_KEEPALIVE dumb473(void) {}
void EMSCRIPTEN_KEEPALIVE dumb474(void) {}
void EMSCRIPTEN_KEEPALIVE dumb475(void) {}
void EMSCRIPTEN_KEEPALIVE dumb476(void) {}
void EMSCRIPTEN_KEEPALIVE dumb477(void) {}
void EMSCRIPTEN_KEEPALIVE dumb478(void) {}
void EMSCRIPTEN_KEEPALIVE dumb479(void) {}
void EMSCRIPTEN_KEEPALIVE dumb480(void) {}
void EMSCRIPTEN_KEEPALIVE dumb481(void) {}
void EMSCRIPTEN_KEEPALIVE dumb482(void) {}
void EMSCRIPTEN_KEEPALIVE dumb483(void) {}
void EMSCRIPTEN_KEEPALIVE dumb484(void) {}
void EMSCRIPTEN_KEEPALIVE dumb485(void) {}
void EMSCRIPTEN_KEEPALIVE dumb486(void) {}
void EMSCRIPTEN_KEEPALIVE dumb487(void) {}
void EMSCRIPTEN_KEEPALIVE dumb488(void) {}
void EMSCRIPTEN_KEEPALIVE dumb489(void) {}
void EMSCRIPTEN_KEEPALIVE dumb490(void) {}
void EMSCRIPTEN_KEEPALIVE dumb491(void) {}
void EMSCRIPTEN_KEEPALIVE dumb492(void) {}
void EMSCRIPTEN_KEEPALIVE dumb493(void) {}
void EMSCRIPTEN_KEEPALIVE dumb494(void) {}
void EMSCRIPTEN_KEEPALIVE dumb495(void) {}
void EMSCRIPTEN_KEEPALIVE dumb496(void) {}
void EMSCRIPTEN_KEEPALIVE dumb497(void) {}
void EMSCRIPTEN_KEEPALIVE dumb498(void) {}
void EMSCRIPTEN_KEEPALIVE dumb499(void) {}
void EMSCRIPTEN_KEEPALIVE dumb500(void) {}
void EMSCRIPTEN_KEEPALIVE dumb501(void) {}
void EMSCRIPTEN_KEEPALIVE dumb502(void) {}
void EMSCRIPTEN_KEEPALIVE dumb503(void) {}
void EMSCRIPTEN_KEEPALIVE dumb504(void) {}
void EMSCRIPTEN_KEEPALIVE dumb505(void) {}
void EMSCRIPTEN_KEEPALIVE dumb506(void) {}
void EMSCRIPTEN_KEEPALIVE dumb507(void) {}
void EMSCRIPTEN_KEEPALIVE dumb508(void) {}
void EMSCRIPTEN_KEEPALIVE dumb509(void) {}
void EMSCRIPTEN_KEEPALIVE dumb510(void) {}
void EMSCRIPTEN_KEEPALIVE dumb511(void) {}
void EMSCRIPTEN_KEEPALIVE dumb512(void) {}
void EMSCRIPTEN_KEEPALIVE dumb513(void) {}
void EMSCRIPTEN_KEEPALIVE dumb514(void) {}
void EMSCRIPTEN_KEEPALIVE dumb515(void) {}
void EMSCRIPTEN_KEEPALIVE dumb516(void) {}
void EMSCRIPTEN_KEEPALIVE dumb517(void) {}
void EMSCRIPTEN_KEEPALIVE dumb518(void) {}
void EMSCRIPTEN_KEEPALIVE dumb519(void) {}
void EMSCRIPTEN_KEEPALIVE dumb520(void) {}
void EMSCRIPTEN_KEEPALIVE dumb521(void) {}
void EMSCRIPTEN_KEEPALIVE dumb522(void) {}
void EMSCRIPTEN_KEEPALIVE dumb523(void) {}
void EMSCRIPTEN_KEEPALIVE dumb524(void) {}
void EMSCRIPTEN_KEEPALIVE dumb525(void) {}
void EMSCRIPTEN_KEEPALIVE dumb526(void) {}
void EMSCRIPTEN_KEEPALIVE dumb527(void) {}
void EMSCRIPTEN_KEEPALIVE dumb528(void) {}
void EMSCRIPTEN_KEEPALIVE dumb529(void) {}
void EMSCRIPTEN_KEEPALIVE dumb530(void) {}
void EMSCRIPTEN_KEEPALIVE dumb531(void) {}
void EMSCRIPTEN_KEEPALIVE dumb532(void) {}
void EMSCRIPTEN_KEEPALIVE dumb533(void) {}
void EMSCRIPTEN_KEEPALIVE dumb534(void) {}
void EMSCRIPTEN_KEEPALIVE dumb535(void) {}
void EMSCRIPTEN_KEEPALIVE dumb536(void) {}
void EMSCRIPTEN_KEEPALIVE dumb537(void) {}
void EMSCRIPTEN_KEEPALIVE dumb538(void) {}
void EMSCRIPTEN_KEEPALIVE dumb539(void) {}
void EMSCRIPTEN_KEEPALIVE dumb540(void) {}
void EMSCRIPTEN_KEEPALIVE dumb541(void) {}
void EMSCRIPTEN_KEEPALIVE dumb542(void) {}
void EMSCRIPTEN_KEEPALIVE dumb543(void) {}
void EMSCRIPTEN_KEEPALIVE dumb544(void) {}
void EMSCRIPTEN_KEEPALIVE dumb545(void) {}
void EMSCRIPTEN_KEEPALIVE dumb546(void) {}
void EMSCRIPTEN_KEEPALIVE dumb547(void) {}
void EMSCRIPTEN_KEEPALIVE dumb548(void) {}
void EMSCRIPTEN_KEEPALIVE dumb549(void) {}
void EMSCRIPTEN_KEEPALIVE dumb550(void) {}
void EMSCRIPTEN_KEEPALIVE dumb551(void) {}
void EMSCRIPTEN_KEEPALIVE dumb552(void) {}
void EMSCRIPTEN_KEEPALIVE dumb553(void) {}
void EMSCRIPTEN_KEEPALIVE dumb554(void) {}
void EMSCRIPTEN_KEEPALIVE dumb555(void) {}
void EMSCRIPTEN_KEEPALIVE dumb556(void) {}
void EMSCRIPTEN_KEEPALIVE dumb557(void) {}
void EMSCRIPTEN_KEEPALIVE dumb558(void) {}
void EMSCRIPTEN_KEEPALIVE dumb559(void) {}
void EMSCRIPTEN_KEEPALIVE dumb560(void) {}
void EMSCRIPTEN_KEEPALIVE dumb561(void) {}
void EMSCRIPTEN_KEEPALIVE dumb562(void) {}
void EMSCRIPTEN_KEEPALIVE dumb563(void) {}
void EMSCRIPTEN_KEEPALIVE dumb564(void) {}
void EMSCRIPTEN_KEEPALIVE dumb565(void) {}
void EMSCRIPTEN_KEEPALIVE dumb566(void) {}
void EMSCRIPTEN_KEEPALIVE dumb567(void) {}
void EMSCRIPTEN_KEEPALIVE dumb568(void) {}
void EMSCRIPTEN_KEEPALIVE dumb569(void) {}
void EMSCRIPTEN_KEEPALIVE dumb570(void) {}
void EMSCRIPTEN_KEEPALIVE dumb571(void) {}
void EMSCRIPTEN_KEEPALIVE dumb572(void) {}
void EMSCRIPTEN_KEEPALIVE dumb573(void) {}
void EMSCRIPTEN_KEEPALIVE dumb574(void) {}
void EMSCRIPTEN_KEEPALIVE dumb575(void) {}
void EMSCRIPTEN_KEEPALIVE dumb576(void) {}
void EMSCRIPTEN_KEEPALIVE dumb577(void) {}
void EMSCRIPTEN_KEEPALIVE dumb578(void) {}
void EMSCRIPTEN_KEEPALIVE dumb579(void) {}
void EMSCRIPTEN_KEEPALIVE dumb580(void) {}
void EMSCRIPTEN_KEEPALIVE dumb581(void) {}
void EMSCRIPTEN_KEEPALIVE dumb582(void) {}
void EMSCRIPTEN_KEEPALIVE dumb583(void) {}
void EMSCRIPTEN_KEEPALIVE dumb584(void) {}
void EMSCRIPTEN_KEEPALIVE dumb585(void) {}
void EMSCRIPTEN_KEEPALIVE dumb586(void) {}
void EMSCRIPTEN_KEEPALIVE dumb587(void) {}
void EMSCRIPTEN_KEEPALIVE dumb588(void) {}
void EMSCRIPTEN_KEEPALIVE dumb589(void) {}
void EMSCRIPTEN_KEEPALIVE dumb590(void) {}
void EMSCRIPTEN_KEEPALIVE dumb591(void) {}
void EMSCRIPTEN_KEEPALIVE dumb592(void) {}
void EMSCRIPTEN_KEEPALIVE dumb593(void) {}
void EMSCRIPTEN_KEEPALIVE dumb594(void) {}
void EMSCRIPTEN_KEEPALIVE dumb595(void) {}
void EMSCRIPTEN_KEEPALIVE dumb596(void) {}
void EMSCRIPTEN_KEEPALIVE dumb597(void) {}
void EMSCRIPTEN_KEEPALIVE dumb598(void) {}
void EMSCRIPTEN_KEEPALIVE dumb599(void) {}
void EMSCRIPTEN_KEEPALIVE dumb600(void) {}
void EMSCRIPTEN_KEEPALIVE dumb601(void) {}
void EMSCRIPTEN_KEEPALIVE dumb602(void) {}
void EMSCRIPTEN_KEEPALIVE dumb603(void) {}
void EMSCRIPTEN_KEEPALIVE dumb604(void) {}
void EMSCRIPTEN_KEEPALIVE dumb605(void) {}
void EMSCRIPTEN_KEEPALIVE dumb606(void) {}
void EMSCRIPTEN_KEEPALIVE dumb607(void) {}
void EMSCRIPTEN_KEEPALIVE dumb608(void) {}
void EMSCRIPTEN_KEEPALIVE dumb609(void) {}
void EMSCRIPTEN_KEEPALIVE dumb610(void) {}
void EMSCRIPTEN_KEEPALIVE dumb611(void) {}
void EMSCRIPTEN_KEEPALIVE dumb612(void) {}
void EMSCRIPTEN_KEEPALIVE dumb613(void) {}
void EMSCRIPTEN_KEEPALIVE dumb614(void) {}
void EMSCRIPTEN_KEEPALIVE dumb615(void) {}
void EMSCRIPTEN_KEEPALIVE dumb616(void) {}
void EMSCRIPTEN_KEEPALIVE dumb617(void) {}
void EMSCRIPTEN_KEEPALIVE dumb618(void) {}
void EMSCRIPTEN_KEEPALIVE dumb619(void) {}
void EMSCRIPTEN_KEEPALIVE dumb620(void) {}
void EMSCRIPTEN_KEEPALIVE dumb621(void) {}
void EMSCRIPTEN_KEEPALIVE dumb622(void) {}
void EMSCRIPTEN_KEEPALIVE dumb623(void) {}
void EMSCRIPTEN_KEEPALIVE dumb624(void) {}
void EMSCRIPTEN_KEEPALIVE dumb625(void) {}
void EMSCRIPTEN_KEEPALIVE dumb626(void) {}
void EMSCRIPTEN_KEEPALIVE dumb627(void) {}
void EMSCRIPTEN_KEEPALIVE dumb628(void) {}
void EMSCRIPTEN_KEEPALIVE dumb629(void) {}
void EMSCRIPTEN_KEEPALIVE dumb630(void) {}
void EMSCRIPTEN_KEEPALIVE dumb631(void) {}
void EMSCRIPTEN_KEEPALIVE dumb632(void) {}
void EMSCRIPTEN_KEEPALIVE dumb633(void) {}
void EMSCRIPTEN_KEEPALIVE dumb634(void) {}
void EMSCRIPTEN_KEEPALIVE dumb635(void) {}
void EMSCRIPTEN_KEEPALIVE dumb636(void) {}
void EMSCRIPTEN_KEEPALIVE dumb637(void) {}
void EMSCRIPTEN_KEEPALIVE dumb638(void) {}
void EMSCRIPTEN_KEEPALIVE dumb639(void) {}
void EMSCRIPTEN_KEEPALIVE dumb640(void) {}
void EMSCRIPTEN_KEEPALIVE dumb641(void) {}
void EMSCRIPTEN_KEEPALIVE dumb642(void) {}
void EMSCRIPTEN_KEEPALIVE dumb643(void) {}
void EMSCRIPTEN_KEEPALIVE dumb644(void) {}
void EMSCRIPTEN_KEEPALIVE dumb645(void) {}
void EMSCRIPTEN_KEEPALIVE dumb646(void) {}
void EMSCRIPTEN_KEEPALIVE dumb647(void) {}
void EMSCRIPTEN_KEEPALIVE dumb648(void) {}
void EMSCRIPTEN_KEEPALIVE dumb649(void) {}
void EMSCRIPTEN_KEEPALIVE dumb650(void) {}
void EMSCRIPTEN_KEEPALIVE dumb651(void) {}
void EMSCRIPTEN_KEEPALIVE dumb652(void) {}
void EMSCRIPTEN_KEEPALIVE dumb653(void) {}
void EMSCRIPTEN_KEEPALIVE dumb654(void) {}
void EMSCRIPTEN_KEEPALIVE dumb655(void) {}
void EMSCRIPTEN_KEEPALIVE dumb656(void) {}
void EMSCRIPTEN_KEEPALIVE dumb657(void) {}
void EMSCRIPTEN_KEEPALIVE dumb658(void) {}
void EMSCRIPTEN_KEEPALIVE dumb659(void) {}
void EMSCRIPTEN_KEEPALIVE dumb660(void) {}
void EMSCRIPTEN_KEEPALIVE dumb661(void) {}
void EMSCRIPTEN_KEEPALIVE dumb662(void) {}
void EMSCRIPTEN_KEEPALIVE dumb663(void) {}
void EMSCRIPTEN_KEEPALIVE dumb664(void) {}
void EMSCRIPTEN_KEEPALIVE dumb665(void) {}
void EMSCRIPTEN_KEEPALIVE dumb666(void) {}
void EMSCRIPTEN_KEEPALIVE dumb667(void) {}
void EMSCRIPTEN_KEEPALIVE dumb668(void) {}
void EMSCRIPTEN_KEEPALIVE dumb669(void) {}
void EMSCRIPTEN_KEEPALIVE dumb670(void) {}
void EMSCRIPTEN_KEEPALIVE dumb671(void) {}
void EMSCRIPTEN_KEEPALIVE dumb672(void) {}
void EMSCRIPTEN_KEEPALIVE dumb673(void) {}
void EMSCRIPTEN_KEEPALIVE dumb674(void) {}
void EMSCRIPTEN_KEEPALIVE dumb675(void) {}
void EMSCRIPTEN_KEEPALIVE dumb676(void) {}
void EMSCRIPTEN_KEEPALIVE dumb677(void) {}
void EMSCRIPTEN_KEEPALIVE dumb678(void) {}
void EMSCRIPTEN_KEEPALIVE dumb679(void) {}
void EMSCRIPTEN_KEEPALIVE dumb680(void) {}
void EMSCRIPTEN_KEEPALIVE dumb681(void) {}
void EMSCRIPTEN_KEEPALIVE dumb682(void) {}
void EMSCRIPTEN_KEEPALIVE dumb683(void) {}
void EMSCRIPTEN_KEEPALIVE dumb684(void) {}
void EMSCRIPTEN_KEEPALIVE dumb685(void) {}
void EMSCRIPTEN_KEEPALIVE dumb686(void) {}
void EMSCRIPTEN_KEEPALIVE dumb687(void) {}
void EMSCRIPTEN_KEEPALIVE dumb688(void) {}
void EMSCRIPTEN_KEEPALIVE dumb689(void) {}
void EMSCRIPTEN_KEEPALIVE dumb690(void) {}
void EMSCRIPTEN_KEEPALIVE dumb691(void) {}
void EMSCRIPTEN_KEEPALIVE dumb692(void) {}
void EMSCRIPTEN_KEEPALIVE dumb693(void) {}
void EMSCRIPTEN_KEEPALIVE dumb694(void) {}
void EMSCRIPTEN_KEEPALIVE dumb695(void) {}
void EMSCRIPTEN_KEEPALIVE dumb696(void) {}
void EMSCRIPTEN_KEEPALIVE dumb697(void) {}
void EMSCRIPTEN_KEEPALIVE dumb698(void) {}
void EMSCRIPTEN_KEEPALIVE dumb699(void) {}
void EMSCRIPTEN_KEEPALIVE (*dumb[700])(void) = {
dumb000,
dumb001,
dumb002,
dumb003,
dumb004,
dumb005,
dumb006,
dumb007,
dumb008,
dumb009,
dumb010,
dumb011,
dumb012,
dumb013,
dumb014,
dumb015,
dumb016,
dumb017,
dumb018,
dumb019,
dumb020,
dumb021,
dumb022,
dumb023,
dumb024,
dumb025,
dumb026,
dumb027,
dumb028,
dumb029,
dumb030,
dumb031,
dumb032,
dumb033,
dumb034,
dumb035,
dumb036,
dumb037,
dumb038,
dumb039,
dumb040,
dumb041,
dumb042,
dumb043,
dumb044,
dumb045,
dumb046,
dumb047,
dumb048,
dumb049,
dumb050,
dumb051,
dumb052,
dumb053,
dumb054,
dumb055,
dumb056,
dumb057,
dumb058,
dumb059,
dumb060,
dumb061,
dumb062,
dumb063,
dumb064,
dumb065,
dumb066,
dumb067,
dumb068,
dumb069,
dumb070,
dumb071,
dumb072,
dumb073,
dumb074,
dumb075,
dumb076,
dumb077,
dumb078,
dumb079,
dumb080,
dumb081,
dumb082,
dumb083,
dumb084,
dumb085,
dumb086,
dumb087,
dumb088,
dumb089,
dumb090,
dumb091,
dumb092,
dumb093,
dumb094,
dumb095,
dumb096,
dumb097,
dumb098,
dumb099,
dumb100,
dumb101,
dumb102,
dumb103,
dumb104,
dumb105,
dumb106,
dumb107,
dumb108,
dumb109,
dumb110,
dumb111,
dumb112,
dumb113,
dumb114,
dumb115,
dumb116,
dumb117,
dumb118,
dumb119,
dumb120,
dumb121,
dumb122,
dumb123,
dumb124,
dumb125,
dumb126,
dumb127,
dumb128,
dumb129,
dumb130,
dumb131,
dumb132,
dumb133,
dumb134,
dumb135,
dumb136,
dumb137,
dumb138,
dumb139,
dumb140,
dumb141,
dumb142,
dumb143,
dumb144,
dumb145,
dumb146,
dumb147,
dumb148,
dumb149,
dumb150,
dumb151,
dumb152,
dumb153,
dumb154,
dumb155,
dumb156,
dumb157,
dumb158,
dumb159,
dumb160,
dumb161,
dumb162,
dumb163,
dumb164,
dumb165,
dumb166,
dumb167,
dumb168,
dumb169,
dumb170,
dumb171,
dumb172,
dumb173,
dumb174,
dumb175,
dumb176,
dumb177,
dumb178,
dumb179,
dumb180,
dumb181,
dumb182,
dumb183,
dumb184,
dumb185,
dumb186,
dumb187,
dumb188,
dumb189,
dumb190,
dumb191,
dumb192,
dumb193,
dumb194,
dumb195,
dumb196,
dumb197,
dumb198,
dumb199,
dumb200,
dumb201,
dumb202,
dumb203,
dumb204,
dumb205,
dumb206,
dumb207,
dumb208,
dumb209,
dumb210,
dumb211,
dumb212,
dumb213,
dumb214,
dumb215,
dumb216,
dumb217,
dumb218,
dumb219,
dumb220,
dumb221,
dumb222,
dumb223,
dumb224,
dumb225,
dumb226,
dumb227,
dumb228,
dumb229,
dumb230,
dumb231,
dumb232,
dumb233,
dumb234,
dumb235,
dumb236,
dumb237,
dumb238,
dumb239,
dumb240,
dumb241,
dumb242,
dumb243,
dumb244,
dumb245,
dumb246,
dumb247,
dumb248,
dumb249,
dumb250,
dumb251,
dumb252,
dumb253,
dumb254,
dumb255,
dumb256,
dumb257,
dumb258,
dumb259,
dumb260,
dumb261,
dumb262,
dumb263,
dumb264,
dumb265,
dumb266,
dumb267,
dumb268,
dumb269,
dumb270,
dumb271,
dumb272,
dumb273,
dumb274,
dumb275,
dumb276,
dumb277,
dumb278,
dumb279,
dumb280,
dumb281,
dumb282,
dumb283,
dumb284,
dumb285,
dumb286,
dumb287,
dumb288,
dumb289,
dumb290,
dumb291,
dumb292,
dumb293,
dumb294,
dumb295,
dumb296,
dumb297,
dumb298,
dumb299,
dumb300,
dumb301,
dumb302,
dumb303,
dumb304,
dumb305,
dumb306,
dumb307,
dumb308,
dumb309,
dumb310,
dumb311,
dumb312,
dumb313,
dumb314,
dumb315,
dumb316,
dumb317,
dumb318,
dumb319,
dumb320,
dumb321,
dumb322,
dumb323,
dumb324,
dumb325,
dumb326,
dumb327,
dumb328,
dumb329,
dumb330,
dumb331,
dumb332,
dumb333,
dumb334,
dumb335,
dumb336,
dumb337,
dumb338,
dumb339,
dumb340,
dumb341,
dumb342,
dumb343,
dumb344,
dumb345,
dumb346,
dumb347,
dumb348,
dumb349,
dumb350,
dumb351,
dumb352,
dumb353,
dumb354,
dumb355,
dumb356,
dumb357,
dumb358,
dumb359,
dumb360,
dumb361,
dumb362,
dumb363,
dumb364,
dumb365,
dumb366,
dumb367,
dumb368,
dumb369,
dumb370,
dumb371,
dumb372,
dumb373,
dumb374,
dumb375,
dumb376,
dumb377,
dumb378,
dumb379,
dumb380,
dumb381,
dumb382,
dumb383,
dumb384,
dumb385,
dumb386,
dumb387,
dumb388,
dumb389,
dumb390,
dumb391,
dumb392,
dumb393,
dumb394,
dumb395,
dumb396,
dumb397,
dumb398,
dumb399,
dumb400,
dumb401,
dumb402,
dumb403,
dumb404,
dumb405,
dumb406,
dumb407,
dumb408,
dumb409,
dumb410,
dumb411,
dumb412,
dumb413,
dumb414,
dumb415,
dumb416,
dumb417,
dumb418,
dumb419,
dumb420,
dumb421,
dumb422,
dumb423,
dumb424,
dumb425,
dumb426,
dumb427,
dumb428,
dumb429,
dumb430,
dumb431,
dumb432,
dumb433,
dumb434,
dumb435,
dumb436,
dumb437,
dumb438,
dumb439,
dumb440,
dumb441,
dumb442,
dumb443,
dumb444,
dumb445,
dumb446,
dumb447,
dumb448,
dumb449,
dumb450,
dumb451,
dumb452,
dumb453,
dumb454,
dumb455,
dumb456,
dumb457,
dumb458,
dumb459,
dumb460,
dumb461,
dumb462,
dumb463,
dumb464,
dumb465,
dumb466,
dumb467,
dumb468,
dumb469,
dumb470,
dumb471,
dumb472,
dumb473,
dumb474,
dumb475,
dumb476,
dumb477,
dumb478,
dumb479,
dumb480,
dumb481,
dumb482,
dumb483,
dumb484,
dumb485,
dumb486,
dumb487,
dumb488,
dumb489,
dumb490,
dumb491,
dumb492,
dumb493,
dumb494,
dumb495,
dumb496,
dumb497,
dumb498,
dumb499,
dumb500,
dumb501,
dumb502,
dumb503,
dumb504,
dumb505,
dumb506,
dumb507,
dumb508,
dumb509,
dumb510,
dumb511,
dumb512,
dumb513,
dumb514,
dumb515,
dumb516,
dumb517,
dumb518,
dumb519,
dumb520,
dumb521,
dumb522,
dumb523,
dumb524,
dumb525,
dumb526,
dumb527,
dumb528,
dumb529,
dumb530,
dumb531,
dumb532,
dumb533,
dumb534,
dumb535,
dumb536,
dumb537,
dumb538,
dumb539,
dumb540,
dumb541,
dumb542,
dumb543,
dumb544,
dumb545,
dumb546,
dumb547,
dumb548,
dumb549,
dumb550,
dumb551,
dumb552,
dumb553,
dumb554,
dumb555,
dumb556,
dumb557,
dumb558,
dumb559,
dumb560,
dumb561,
dumb562,
dumb563,
dumb564,
dumb565,
dumb566,
dumb567,
dumb568,
dumb569,
dumb570,
dumb571,
dumb572,
dumb573,
dumb574,
dumb575,
dumb576,
dumb577,
dumb578,
dumb579,
dumb580,
dumb581,
dumb582,
dumb583,
dumb584,
dumb585,
dumb586,
dumb587,
dumb588,
dumb589,
dumb590,
dumb591,
dumb592,
dumb593,
dumb594,
dumb595,
dumb596,
dumb597,
dumb598,
dumb599,
dumb600,
dumb601,
dumb602,
dumb603,
dumb604,
dumb605,
dumb606,
dumb607,
dumb608,
dumb609,
dumb610,
dumb611,
dumb612,
dumb613,
dumb614,
dumb615,
dumb616,
dumb617,
dumb618,
dumb619,
dumb620,
dumb621,
dumb622,
dumb623,
dumb624,
dumb625,
dumb626,
dumb627,
dumb628,
dumb629,
dumb630,
dumb631,
dumb632,
dumb633,
dumb634,
dumb635,
dumb636,
dumb637,
dumb638,
dumb639,
dumb640,
dumb641,
dumb642,
dumb643,
dumb644,
dumb645,
dumb646,
dumb647,
dumb648,
dumb649,
dumb650,
dumb651,
dumb652,
dumb653,
dumb654,
dumb655,
dumb656,
dumb657,
dumb658,
dumb659,
dumb660,
dumb661,
dumb662,
dumb663,
dumb664,
dumb665,
dumb666,
dumb667,
dumb668,
dumb669,
dumb670,
dumb671,
dumb672,
dumb673,
dumb674,
dumb675,
dumb676,
dumb677,
dumb678,
dumb679,
dumb680,
dumb681,
dumb682,
dumb683,
dumb684,
dumb685,
dumb686,
dumb687,
dumb688,
dumb689,
dumb690,
dumb691,
dumb692,
dumb693,
dumb694,
dumb695,
dumb696,
dumb697,
dumb698,
dumb699
};
#endif
#include "sq.h"
#include "OpenSmalltalkVM.h"

int
main(int argc, const char **argv)
{
    return osvm_main(argc, argv);
}

sqInt
ioCanCatchFFIExceptions() { return 1; }
