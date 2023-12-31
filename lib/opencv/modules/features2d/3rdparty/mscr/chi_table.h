/*
**
**                           License Agreement
**                           For chi_table.h
**
** Copyright (C) 2007 Per-Erik Forssen, all rights reserved.
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
**   * Redistribution's of source code must retain the above copyright notice,
**     this list of conditions and the following disclaimer.
**
**   * Redistribution's in binary form must reproduce the above copyright notice,
**     this list of conditions and the following disclaimer in the documentation
**     and/or other materials provided with the distribution.
**
**   * The name of the copyright holders may not be used to endorse or promote products
**     derived from this software without specific prior written permission.
**
** This software is provided by the copyright holders and contributors "as is" and
** any express or implied warranties, including, but not limited to, the implied
** warranties of merchantability and fitness for a particular purpose are disclaimed.
** In no event shall the Intel Corporation or contributors be liable for any direct,
** indirect, incidental, special, exemplary, or consequential damages
** (including, but not limited to, procurement of substitute goods or services;
** loss of use, data, or profits; or business interruption) however caused
** and on any theory of liability, whether in contract, strict liability,
** or tort (including negligence or otherwise) arising in any way out of
** the use of this software, even if advised of the possibility of such damage.
**
** Content origin: http://users.isy.liu.se/cvl/perfo/software/chi_table.h
*/
#define TABLE_SIZE 400

static double chitab3[]={0,  0.0150057,  0.0239478,  0.0315227,
                  0.0383427,  0.0446605,  0.0506115,  0.0562786,
                  0.0617174,  0.0669672,  0.0720573,  0.0770099,
                  0.081843,  0.0865705,  0.0912043,  0.0957541,
                  0.100228,  0.104633,  0.108976,  0.113261,
                  0.117493,  0.121676,  0.125814,  0.12991,
                  0.133967,  0.137987,  0.141974,  0.145929,
                  0.149853,  0.15375,  0.15762,  0.161466,
                  0.165287,  0.169087,  0.172866,  0.176625,
                  0.180365,  0.184088,  0.187794,  0.191483,
                  0.195158,  0.198819,  0.202466,  0.2061,
                  0.209722,  0.213332,  0.216932,  0.220521,
                  0.2241,  0.22767,  0.231231,  0.234783,
                  0.238328,  0.241865,  0.245395,  0.248918,
                  0.252435,  0.255947,  0.259452,  0.262952,
                  0.266448,  0.269939,  0.273425,  0.276908,
                  0.280386,  0.283862,  0.287334,  0.290803,
                  0.29427,  0.297734,  0.301197,  0.304657,
                  0.308115,  0.311573,  0.315028,  0.318483,
                  0.321937,  0.32539,  0.328843,  0.332296,
                  0.335749,  0.339201,  0.342654,  0.346108,
                  0.349562,  0.353017,  0.356473,  0.35993,
                  0.363389,  0.366849,  0.37031,  0.373774,
                  0.377239,  0.380706,  0.384176,  0.387648,
                  0.391123,  0.3946,  0.39808,  0.401563,
                  0.405049,  0.408539,  0.412032,  0.415528,
                  0.419028,  0.422531,  0.426039,  0.429551,
                  0.433066,  0.436586,  0.440111,  0.44364,
                  0.447173,  0.450712,  0.454255,  0.457803,
                  0.461356,  0.464915,  0.468479,  0.472049,
                  0.475624,  0.479205,  0.482792,  0.486384,
                  0.489983,  0.493588,  0.4972,  0.500818,
                  0.504442,  0.508073,  0.511711,  0.515356,
                  0.519008,  0.522667,  0.526334,  0.530008,
                  0.533689,  0.537378,  0.541075,  0.54478,
                  0.548492,  0.552213,  0.555942,  0.55968,
                  0.563425,  0.56718,  0.570943,  0.574715,
                  0.578497,  0.582287,  0.586086,  0.589895,
                  0.593713,  0.597541,  0.601379,  0.605227,
                  0.609084,  0.612952,  0.61683,  0.620718,
                  0.624617,  0.628526,  0.632447,  0.636378,
                  0.64032,  0.644274,  0.648239,  0.652215,
                  0.656203,  0.660203,  0.664215,  0.668238,
                  0.672274,  0.676323,  0.680384,  0.684457,
                  0.688543,  0.692643,  0.696755,  0.700881,
                  0.70502,  0.709172,  0.713339,  0.717519,
                  0.721714,  0.725922,  0.730145,  0.734383,
                  0.738636,  0.742903,  0.747185,  0.751483,
                  0.755796,  0.760125,  0.76447,  0.768831,
                  0.773208,  0.777601,  0.782011,  0.786438,
                  0.790882,  0.795343,  0.799821,  0.804318,
                  0.808831,  0.813363,  0.817913,  0.822482,
                  0.827069,  0.831676,  0.836301,  0.840946,
                  0.84561,  0.850295,  0.854999,  0.859724,
                  0.864469,  0.869235,  0.874022,  0.878831,
                  0.883661,  0.888513,  0.893387,  0.898284,
                  0.903204,  0.908146,  0.913112,  0.918101,
                  0.923114,  0.928152,  0.933214,  0.938301,
                  0.943413,  0.94855,  0.953713,  0.958903,
                  0.964119,  0.969361,  0.974631,  0.979929,
                  0.985254,  0.990608,  0.99599,  1.0014,
                  1.00684,  1.01231,  1.01781,  1.02335,
                  1.02891,  1.0345,  1.04013,  1.04579,
                  1.05148,  1.05721,  1.06296,  1.06876,
                  1.07459,  1.08045,  1.08635,  1.09228,
                  1.09826,  1.10427,  1.11032,  1.1164,
                  1.12253,  1.1287,  1.1349,  1.14115,
                  1.14744,  1.15377,  1.16015,  1.16656,
                  1.17303,  1.17954,  1.18609,  1.19269,
                  1.19934,  1.20603,  1.21278,  1.21958,
                  1.22642,  1.23332,  1.24027,  1.24727,
                  1.25433,  1.26144,  1.26861,  1.27584,
                  1.28312,  1.29047,  1.29787,  1.30534,
                  1.31287,  1.32046,  1.32812,  1.33585,
                  1.34364,  1.3515,  1.35943,  1.36744,
                  1.37551,  1.38367,  1.39189,  1.4002,
                  1.40859,  1.41705,  1.42561,  1.43424,
                  1.44296,  1.45177,  1.46068,  1.46967,
                  1.47876,  1.48795,  1.49723,  1.50662,
                  1.51611,  1.52571,  1.53541,  1.54523,
                  1.55517,  1.56522,  1.57539,  1.58568,
                  1.59611,  1.60666,  1.61735,  1.62817,
                  1.63914,  1.65025,  1.66152,  1.67293,
                  1.68451,  1.69625,  1.70815,  1.72023,
                  1.73249,  1.74494,  1.75757,  1.77041,
                  1.78344,  1.79669,  1.81016,  1.82385,
                  1.83777,  1.85194,  1.86635,  1.88103,
                  1.89598,  1.91121,  1.92674,  1.94257,
                  1.95871,  1.97519,  1.99201,  2.0092,
                  2.02676,  2.04471,  2.06309,  2.08189,
                  2.10115,  2.12089,  2.14114,  2.16192,
                  2.18326,  2.2052,  2.22777,  2.25101,
                  2.27496,  2.29966,  2.32518,  2.35156,
                  2.37886,  2.40717,  2.43655,  2.46709,
                  2.49889,  2.53206,  2.56673,  2.60305,
                  2.64117,  2.6813,  2.72367,  2.76854,
                  2.81623,  2.86714,  2.92173,  2.98059,
                  3.04446,  3.1143,  3.19135,  3.27731,
                  3.37455,  3.48653,  3.61862,  3.77982,
                  3.98692,  4.2776,  4.77167,  133.333 };
