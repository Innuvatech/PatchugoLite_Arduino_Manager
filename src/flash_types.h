#ifndef FLASH_TYPES_H
#define FLASH_TYPES_H

#include <Arduino.h>
#include <stdbool.h>

#ifndef PATCHUGO_FLASH_TYPES
#error "flash_types.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_INTERNAL_USE
#include "spi_manager.h"
#undef PATCHUGO_INTERNAL_USE

#define FLASH_SECTOR_SIZE   0x1000
#define FLASH_SECTOR_ADDRESS(sectorN) (sectorN * FLASH_SECTOR_SIZE)

#define FLASH_PAGE_SIZE     0x100
#define FLASH_PAGE_ADDRESS(pageN) (pageN * FLASH_PAGE_SIZE)

enum class Flash_Sector {
    SECTOR_0 = FLASH_SECTOR_ADDRESS(0),
    SECTOR_1 = FLASH_SECTOR_ADDRESS(1),
    SECTOR_2 = FLASH_SECTOR_ADDRESS(2),
    SECTOR_3 = FLASH_SECTOR_ADDRESS(3),
    SECTOR_4 = FLASH_SECTOR_ADDRESS(4),
    SECTOR_5 = FLASH_SECTOR_ADDRESS(5),
    SECTOR_6 = FLASH_SECTOR_ADDRESS(6),
    SECTOR_7 = FLASH_SECTOR_ADDRESS(7),
    SECTOR_8 = FLASH_SECTOR_ADDRESS(8),
    SECTOR_9 = FLASH_SECTOR_ADDRESS(9),
    SECTOR_10 = FLASH_SECTOR_ADDRESS(10),
    SECTOR_11 = FLASH_SECTOR_ADDRESS(11),
    SECTOR_12 = FLASH_SECTOR_ADDRESS(12),
    SECTOR_13 = FLASH_SECTOR_ADDRESS(13),
    SECTOR_14 = FLASH_SECTOR_ADDRESS(14),
    SECTOR_15 = FLASH_SECTOR_ADDRESS(15),
    SECTOR_16 = FLASH_SECTOR_ADDRESS(16),
    SECTOR_17 = FLASH_SECTOR_ADDRESS(17),
    SECTOR_18 = FLASH_SECTOR_ADDRESS(18),
    SECTOR_19 = FLASH_SECTOR_ADDRESS(19),
    SECTOR_20 = FLASH_SECTOR_ADDRESS(20),
    SECTOR_21 = FLASH_SECTOR_ADDRESS(21),
    SECTOR_22 = FLASH_SECTOR_ADDRESS(22),
    SECTOR_23 = FLASH_SECTOR_ADDRESS(23),
    SECTOR_24 = FLASH_SECTOR_ADDRESS(24),
    SECTOR_25 = FLASH_SECTOR_ADDRESS(25),
    SECTOR_26 = FLASH_SECTOR_ADDRESS(26),
    SECTOR_27 = FLASH_SECTOR_ADDRESS(27),
    SECTOR_28 = FLASH_SECTOR_ADDRESS(28),
    SECTOR_29 = FLASH_SECTOR_ADDRESS(29),
    SECTOR_30 = FLASH_SECTOR_ADDRESS(30),
    SECTOR_31 = FLASH_SECTOR_ADDRESS(31),
    SECTOR_32 = FLASH_SECTOR_ADDRESS(32),
    SECTOR_33 = FLASH_SECTOR_ADDRESS(33),
    SECTOR_34 = FLASH_SECTOR_ADDRESS(34),
    SECTOR_35 = FLASH_SECTOR_ADDRESS(35),
    SECTOR_36 = FLASH_SECTOR_ADDRESS(36),
    SECTOR_37 = FLASH_SECTOR_ADDRESS(37),
    SECTOR_38 = FLASH_SECTOR_ADDRESS(38),
    SECTOR_39 = FLASH_SECTOR_ADDRESS(39),
    SECTOR_40 = FLASH_SECTOR_ADDRESS(40),
    SECTOR_41 = FLASH_SECTOR_ADDRESS(41),
    SECTOR_42 = FLASH_SECTOR_ADDRESS(42),
    SECTOR_43 = FLASH_SECTOR_ADDRESS(43),
    SECTOR_44 = FLASH_SECTOR_ADDRESS(44),
    SECTOR_45 = FLASH_SECTOR_ADDRESS(45),
    SECTOR_46 = FLASH_SECTOR_ADDRESS(46),
    SECTOR_47 = FLASH_SECTOR_ADDRESS(47),
    SECTOR_48 = FLASH_SECTOR_ADDRESS(48),
    SECTOR_49 = FLASH_SECTOR_ADDRESS(49),
    SECTOR_50 = FLASH_SECTOR_ADDRESS(50),
    SECTOR_51 = FLASH_SECTOR_ADDRESS(51),
    SECTOR_52 = FLASH_SECTOR_ADDRESS(52),
    SECTOR_53 = FLASH_SECTOR_ADDRESS(53),
    SECTOR_54 = FLASH_SECTOR_ADDRESS(54),
    SECTOR_55 = FLASH_SECTOR_ADDRESS(55),
    SECTOR_56 = FLASH_SECTOR_ADDRESS(56),
    SECTOR_57 = FLASH_SECTOR_ADDRESS(57),
    SECTOR_58 = FLASH_SECTOR_ADDRESS(58),
    SECTOR_59 = FLASH_SECTOR_ADDRESS(59),
    SECTOR_60 = FLASH_SECTOR_ADDRESS(60),
    SECTOR_61 = FLASH_SECTOR_ADDRESS(61),
    SECTOR_62 = FLASH_SECTOR_ADDRESS(62),
    SECTOR_63 = FLASH_SECTOR_ADDRESS(63),
    SECTOR_64 = FLASH_SECTOR_ADDRESS(64),
    SECTOR_65 = FLASH_SECTOR_ADDRESS(65),
    SECTOR_66 = FLASH_SECTOR_ADDRESS(66),
    SECTOR_67 = FLASH_SECTOR_ADDRESS(67),
    SECTOR_68 = FLASH_SECTOR_ADDRESS(68),
    SECTOR_69 = FLASH_SECTOR_ADDRESS(69),
    SECTOR_70 = FLASH_SECTOR_ADDRESS(70),
    SECTOR_71 = FLASH_SECTOR_ADDRESS(71),
    SECTOR_72 = FLASH_SECTOR_ADDRESS(72),
    SECTOR_73 = FLASH_SECTOR_ADDRESS(73),
    SECTOR_74 = FLASH_SECTOR_ADDRESS(74),
    SECTOR_75 = FLASH_SECTOR_ADDRESS(75),
    SECTOR_76 = FLASH_SECTOR_ADDRESS(76),
    SECTOR_77 = FLASH_SECTOR_ADDRESS(77),
    SECTOR_78 = FLASH_SECTOR_ADDRESS(78),
    SECTOR_79 = FLASH_SECTOR_ADDRESS(79),
    SECTOR_80 = FLASH_SECTOR_ADDRESS(80),
    SECTOR_81 = FLASH_SECTOR_ADDRESS(81),
    SECTOR_82 = FLASH_SECTOR_ADDRESS(82),
    SECTOR_83 = FLASH_SECTOR_ADDRESS(83),
    SECTOR_84 = FLASH_SECTOR_ADDRESS(84),
    SECTOR_85 = FLASH_SECTOR_ADDRESS(85),
    SECTOR_86 = FLASH_SECTOR_ADDRESS(86),
    SECTOR_87 = FLASH_SECTOR_ADDRESS(87),
    SECTOR_88 = FLASH_SECTOR_ADDRESS(88),
    SECTOR_89 = FLASH_SECTOR_ADDRESS(89),
    SECTOR_90 = FLASH_SECTOR_ADDRESS(90),
    SECTOR_91 = FLASH_SECTOR_ADDRESS(91),
    SECTOR_92 = FLASH_SECTOR_ADDRESS(92),
    SECTOR_93 = FLASH_SECTOR_ADDRESS(93),
    SECTOR_94 = FLASH_SECTOR_ADDRESS(94),
    SECTOR_95 = FLASH_SECTOR_ADDRESS(95),
    SECTOR_96 = FLASH_SECTOR_ADDRESS(96),
    SECTOR_97 = FLASH_SECTOR_ADDRESS(97),
    SECTOR_98 = FLASH_SECTOR_ADDRESS(98),
    SECTOR_99 = FLASH_SECTOR_ADDRESS(99),
    SECTOR_100 = FLASH_SECTOR_ADDRESS(100),
    SECTOR_101 = FLASH_SECTOR_ADDRESS(101),
    SECTOR_102 = FLASH_SECTOR_ADDRESS(102),
    SECTOR_103 = FLASH_SECTOR_ADDRESS(103),
    SECTOR_104 = FLASH_SECTOR_ADDRESS(104),
    SECTOR_105 = FLASH_SECTOR_ADDRESS(105),
    SECTOR_106 = FLASH_SECTOR_ADDRESS(106),
    SECTOR_107 = FLASH_SECTOR_ADDRESS(107),
    SECTOR_108 = FLASH_SECTOR_ADDRESS(108),
    SECTOR_109 = FLASH_SECTOR_ADDRESS(109),
    SECTOR_110 = FLASH_SECTOR_ADDRESS(110),
    SECTOR_111 = FLASH_SECTOR_ADDRESS(111),
    SECTOR_112 = FLASH_SECTOR_ADDRESS(112),
    SECTOR_113 = FLASH_SECTOR_ADDRESS(113),
    SECTOR_114 = FLASH_SECTOR_ADDRESS(114),
    SECTOR_115 = FLASH_SECTOR_ADDRESS(115),
    SECTOR_116 = FLASH_SECTOR_ADDRESS(116),
    SECTOR_117 = FLASH_SECTOR_ADDRESS(117),
    SECTOR_118 = FLASH_SECTOR_ADDRESS(118),
    SECTOR_119 = FLASH_SECTOR_ADDRESS(119),
    SECTOR_120 = FLASH_SECTOR_ADDRESS(120),
    SECTOR_121 = FLASH_SECTOR_ADDRESS(121),
    SECTOR_122 = FLASH_SECTOR_ADDRESS(122),
    SECTOR_123 = FLASH_SECTOR_ADDRESS(123),
    SECTOR_124 = FLASH_SECTOR_ADDRESS(124),
    SECTOR_125 = FLASH_SECTOR_ADDRESS(125),
    SECTOR_126 = FLASH_SECTOR_ADDRESS(126),
    SECTOR_127 = FLASH_SECTOR_ADDRESS(127),
    SECTOR_128 = FLASH_SECTOR_ADDRESS(128),
    SECTOR_129 = FLASH_SECTOR_ADDRESS(129),
    SECTOR_130 = FLASH_SECTOR_ADDRESS(130),
    SECTOR_131 = FLASH_SECTOR_ADDRESS(131),
    SECTOR_132 = FLASH_SECTOR_ADDRESS(132),
    SECTOR_133 = FLASH_SECTOR_ADDRESS(133),
    SECTOR_134 = FLASH_SECTOR_ADDRESS(134),
    SECTOR_135 = FLASH_SECTOR_ADDRESS(135),
    SECTOR_136 = FLASH_SECTOR_ADDRESS(136),
    SECTOR_137 = FLASH_SECTOR_ADDRESS(137),
    SECTOR_138 = FLASH_SECTOR_ADDRESS(138),
    SECTOR_139 = FLASH_SECTOR_ADDRESS(139),
    SECTOR_140 = FLASH_SECTOR_ADDRESS(140),
    SECTOR_141 = FLASH_SECTOR_ADDRESS(141),
    SECTOR_142 = FLASH_SECTOR_ADDRESS(142),
    SECTOR_143 = FLASH_SECTOR_ADDRESS(143),
    SECTOR_144 = FLASH_SECTOR_ADDRESS(144),
    SECTOR_145 = FLASH_SECTOR_ADDRESS(145),
    SECTOR_146 = FLASH_SECTOR_ADDRESS(146),
    SECTOR_147 = FLASH_SECTOR_ADDRESS(147),
    SECTOR_148 = FLASH_SECTOR_ADDRESS(148),
    SECTOR_149 = FLASH_SECTOR_ADDRESS(149),
    SECTOR_150 = FLASH_SECTOR_ADDRESS(150),
    SECTOR_151 = FLASH_SECTOR_ADDRESS(151),
    SECTOR_152 = FLASH_SECTOR_ADDRESS(152),
    SECTOR_153 = FLASH_SECTOR_ADDRESS(153),
    SECTOR_154 = FLASH_SECTOR_ADDRESS(154),
    SECTOR_155 = FLASH_SECTOR_ADDRESS(155),
    SECTOR_156 = FLASH_SECTOR_ADDRESS(156),
    SECTOR_157 = FLASH_SECTOR_ADDRESS(157),
    SECTOR_158 = FLASH_SECTOR_ADDRESS(158),
    SECTOR_159 = FLASH_SECTOR_ADDRESS(159),
    SECTOR_160 = FLASH_SECTOR_ADDRESS(160),
    SECTOR_161 = FLASH_SECTOR_ADDRESS(161),
    SECTOR_162 = FLASH_SECTOR_ADDRESS(162),
    SECTOR_163 = FLASH_SECTOR_ADDRESS(163),
    SECTOR_164 = FLASH_SECTOR_ADDRESS(164),
    SECTOR_165 = FLASH_SECTOR_ADDRESS(165),
    SECTOR_166 = FLASH_SECTOR_ADDRESS(166),
    SECTOR_167 = FLASH_SECTOR_ADDRESS(167),
    SECTOR_168 = FLASH_SECTOR_ADDRESS(168),
    SECTOR_169 = FLASH_SECTOR_ADDRESS(169),
    SECTOR_170 = FLASH_SECTOR_ADDRESS(170),
    SECTOR_171 = FLASH_SECTOR_ADDRESS(171),
    SECTOR_172 = FLASH_SECTOR_ADDRESS(172),
    SECTOR_173 = FLASH_SECTOR_ADDRESS(173),
    SECTOR_174 = FLASH_SECTOR_ADDRESS(174),
    SECTOR_175 = FLASH_SECTOR_ADDRESS(175),
    SECTOR_176 = FLASH_SECTOR_ADDRESS(176),
    SECTOR_177 = FLASH_SECTOR_ADDRESS(177),
    SECTOR_178 = FLASH_SECTOR_ADDRESS(178),
    SECTOR_179 = FLASH_SECTOR_ADDRESS(179),
    SECTOR_180 = FLASH_SECTOR_ADDRESS(180),
    SECTOR_181 = FLASH_SECTOR_ADDRESS(181),
    SECTOR_182 = FLASH_SECTOR_ADDRESS(182),
    SECTOR_183 = FLASH_SECTOR_ADDRESS(183),
    SECTOR_184 = FLASH_SECTOR_ADDRESS(184),
    SECTOR_185 = FLASH_SECTOR_ADDRESS(185),
    SECTOR_186 = FLASH_SECTOR_ADDRESS(186),
    SECTOR_187 = FLASH_SECTOR_ADDRESS(187),
    SECTOR_188 = FLASH_SECTOR_ADDRESS(188),
    SECTOR_189 = FLASH_SECTOR_ADDRESS(189),
    SECTOR_190 = FLASH_SECTOR_ADDRESS(190),
    SECTOR_191 = FLASH_SECTOR_ADDRESS(191),
    SECTOR_192 = FLASH_SECTOR_ADDRESS(192),
    SECTOR_193 = FLASH_SECTOR_ADDRESS(193),
    SECTOR_194 = FLASH_SECTOR_ADDRESS(194),
    SECTOR_195 = FLASH_SECTOR_ADDRESS(195),
    SECTOR_196 = FLASH_SECTOR_ADDRESS(196),
    SECTOR_197 = FLASH_SECTOR_ADDRESS(197),
    SECTOR_198 = FLASH_SECTOR_ADDRESS(198),
    SECTOR_199 = FLASH_SECTOR_ADDRESS(199),
    SECTOR_200 = FLASH_SECTOR_ADDRESS(200),
    SECTOR_201 = FLASH_SECTOR_ADDRESS(201),
    SECTOR_202 = FLASH_SECTOR_ADDRESS(202),
    SECTOR_203 = FLASH_SECTOR_ADDRESS(203),
    SECTOR_204 = FLASH_SECTOR_ADDRESS(204),
    SECTOR_205 = FLASH_SECTOR_ADDRESS(205),
    SECTOR_206 = FLASH_SECTOR_ADDRESS(206),
    SECTOR_207 = FLASH_SECTOR_ADDRESS(207),
    SECTOR_208 = FLASH_SECTOR_ADDRESS(208),
    SECTOR_209 = FLASH_SECTOR_ADDRESS(209),
    SECTOR_210 = FLASH_SECTOR_ADDRESS(210),
    SECTOR_211 = FLASH_SECTOR_ADDRESS(211),
    SECTOR_212 = FLASH_SECTOR_ADDRESS(212),
    SECTOR_213 = FLASH_SECTOR_ADDRESS(213),
    SECTOR_214 = FLASH_SECTOR_ADDRESS(214),
    SECTOR_215 = FLASH_SECTOR_ADDRESS(215),
    SECTOR_216 = FLASH_SECTOR_ADDRESS(216),
    SECTOR_217 = FLASH_SECTOR_ADDRESS(217),
    SECTOR_218 = FLASH_SECTOR_ADDRESS(218),
    SECTOR_219 = FLASH_SECTOR_ADDRESS(219),
    SECTOR_220 = FLASH_SECTOR_ADDRESS(220),
    SECTOR_221 = FLASH_SECTOR_ADDRESS(221),
    SECTOR_222 = FLASH_SECTOR_ADDRESS(222),
    SECTOR_223 = FLASH_SECTOR_ADDRESS(223),
    SECTOR_224 = FLASH_SECTOR_ADDRESS(224),
    SECTOR_225 = FLASH_SECTOR_ADDRESS(225),
    SECTOR_226 = FLASH_SECTOR_ADDRESS(226),
    SECTOR_227 = FLASH_SECTOR_ADDRESS(227),
    SECTOR_228 = FLASH_SECTOR_ADDRESS(228),
    SECTOR_229 = FLASH_SECTOR_ADDRESS(229),
    SECTOR_230 = FLASH_SECTOR_ADDRESS(230),
    SECTOR_231 = FLASH_SECTOR_ADDRESS(231),
    SECTOR_232 = FLASH_SECTOR_ADDRESS(232),
    SECTOR_233 = FLASH_SECTOR_ADDRESS(233),
    SECTOR_234 = FLASH_SECTOR_ADDRESS(234),
    SECTOR_235 = FLASH_SECTOR_ADDRESS(235),
    SECTOR_236 = FLASH_SECTOR_ADDRESS(236),
    SECTOR_237 = FLASH_SECTOR_ADDRESS(237),
    SECTOR_238 = FLASH_SECTOR_ADDRESS(238),
    SECTOR_239 = FLASH_SECTOR_ADDRESS(239),
    SECTOR_240 = FLASH_SECTOR_ADDRESS(240),
    SECTOR_241 = FLASH_SECTOR_ADDRESS(241),
    SECTOR_242 = FLASH_SECTOR_ADDRESS(242),
    SECTOR_243 = FLASH_SECTOR_ADDRESS(243),
    SECTOR_244 = FLASH_SECTOR_ADDRESS(244),
    SECTOR_245 = FLASH_SECTOR_ADDRESS(245),
    SECTOR_246 = FLASH_SECTOR_ADDRESS(246),
    SECTOR_247 = FLASH_SECTOR_ADDRESS(247),
    SECTOR_248 = FLASH_SECTOR_ADDRESS(248),
    SECTOR_249 = FLASH_SECTOR_ADDRESS(249),
    SECTOR_250 = FLASH_SECTOR_ADDRESS(250),
    SECTOR_251 = FLASH_SECTOR_ADDRESS(251),
    SECTOR_252 = FLASH_SECTOR_ADDRESS(252),
    SECTOR_253 = FLASH_SECTOR_ADDRESS(253),
    SECTOR_254 = FLASH_SECTOR_ADDRESS(254),
    SECTOR_255 = FLASH_SECTOR_ADDRESS(255),
    SECTOR_256 = FLASH_SECTOR_ADDRESS(256),
    SECTOR_257 = FLASH_SECTOR_ADDRESS(257),
    SECTOR_258 = FLASH_SECTOR_ADDRESS(258),
    SECTOR_259 = FLASH_SECTOR_ADDRESS(259),
    SECTOR_260 = FLASH_SECTOR_ADDRESS(260),
    SECTOR_261 = FLASH_SECTOR_ADDRESS(261),
    SECTOR_262 = FLASH_SECTOR_ADDRESS(262),
    SECTOR_263 = FLASH_SECTOR_ADDRESS(263),
    SECTOR_264 = FLASH_SECTOR_ADDRESS(264),
    SECTOR_265 = FLASH_SECTOR_ADDRESS(265),
    SECTOR_266 = FLASH_SECTOR_ADDRESS(266),
    SECTOR_267 = FLASH_SECTOR_ADDRESS(267),
    SECTOR_268 = FLASH_SECTOR_ADDRESS(268),
    SECTOR_269 = FLASH_SECTOR_ADDRESS(269),
    SECTOR_270 = FLASH_SECTOR_ADDRESS(270),
    SECTOR_271 = FLASH_SECTOR_ADDRESS(271),
    SECTOR_272 = FLASH_SECTOR_ADDRESS(272),
    SECTOR_273 = FLASH_SECTOR_ADDRESS(273),
    SECTOR_274 = FLASH_SECTOR_ADDRESS(274),
    SECTOR_275 = FLASH_SECTOR_ADDRESS(275),
    SECTOR_276 = FLASH_SECTOR_ADDRESS(276),
    SECTOR_277 = FLASH_SECTOR_ADDRESS(277),
    SECTOR_278 = FLASH_SECTOR_ADDRESS(278),
    SECTOR_279 = FLASH_SECTOR_ADDRESS(279),
    SECTOR_280 = FLASH_SECTOR_ADDRESS(280),
    SECTOR_281 = FLASH_SECTOR_ADDRESS(281),
    SECTOR_282 = FLASH_SECTOR_ADDRESS(282),
    SECTOR_283 = FLASH_SECTOR_ADDRESS(283),
    SECTOR_284 = FLASH_SECTOR_ADDRESS(284),
    SECTOR_285 = FLASH_SECTOR_ADDRESS(285),
    SECTOR_286 = FLASH_SECTOR_ADDRESS(286),
    SECTOR_287 = FLASH_SECTOR_ADDRESS(287),
    SECTOR_288 = FLASH_SECTOR_ADDRESS(288),
    SECTOR_289 = FLASH_SECTOR_ADDRESS(289),
    SECTOR_290 = FLASH_SECTOR_ADDRESS(290),
    SECTOR_291 = FLASH_SECTOR_ADDRESS(291),
    SECTOR_292 = FLASH_SECTOR_ADDRESS(292),
    SECTOR_293 = FLASH_SECTOR_ADDRESS(293),
    SECTOR_294 = FLASH_SECTOR_ADDRESS(294),
    SECTOR_295 = FLASH_SECTOR_ADDRESS(295),
    SECTOR_296 = FLASH_SECTOR_ADDRESS(296),
    SECTOR_297 = FLASH_SECTOR_ADDRESS(297),
    SECTOR_298 = FLASH_SECTOR_ADDRESS(298),
    SECTOR_299 = FLASH_SECTOR_ADDRESS(299),
    SECTOR_300 = FLASH_SECTOR_ADDRESS(300),
    SECTOR_301 = FLASH_SECTOR_ADDRESS(301),
    SECTOR_302 = FLASH_SECTOR_ADDRESS(302),
    SECTOR_303 = FLASH_SECTOR_ADDRESS(303),
    SECTOR_304 = FLASH_SECTOR_ADDRESS(304),
    SECTOR_305 = FLASH_SECTOR_ADDRESS(305),
    SECTOR_306 = FLASH_SECTOR_ADDRESS(306),
    SECTOR_307 = FLASH_SECTOR_ADDRESS(307),
    SECTOR_308 = FLASH_SECTOR_ADDRESS(308),
    SECTOR_309 = FLASH_SECTOR_ADDRESS(309),
    SECTOR_310 = FLASH_SECTOR_ADDRESS(310),
    SECTOR_311 = FLASH_SECTOR_ADDRESS(311),
    SECTOR_312 = FLASH_SECTOR_ADDRESS(312),
    SECTOR_313 = FLASH_SECTOR_ADDRESS(313),
    SECTOR_314 = FLASH_SECTOR_ADDRESS(314),
    SECTOR_315 = FLASH_SECTOR_ADDRESS(315),
    SECTOR_316 = FLASH_SECTOR_ADDRESS(316),
    SECTOR_317 = FLASH_SECTOR_ADDRESS(317),
    SECTOR_318 = FLASH_SECTOR_ADDRESS(318),
    SECTOR_319 = FLASH_SECTOR_ADDRESS(319),
    SECTOR_320 = FLASH_SECTOR_ADDRESS(320),
    SECTOR_321 = FLASH_SECTOR_ADDRESS(321),
    SECTOR_322 = FLASH_SECTOR_ADDRESS(322),
    SECTOR_323 = FLASH_SECTOR_ADDRESS(323),
    SECTOR_324 = FLASH_SECTOR_ADDRESS(324),
    SECTOR_325 = FLASH_SECTOR_ADDRESS(325),
    SECTOR_326 = FLASH_SECTOR_ADDRESS(326),
    SECTOR_327 = FLASH_SECTOR_ADDRESS(327),
    SECTOR_328 = FLASH_SECTOR_ADDRESS(328),
    SECTOR_329 = FLASH_SECTOR_ADDRESS(329),
    SECTOR_330 = FLASH_SECTOR_ADDRESS(330),
    SECTOR_331 = FLASH_SECTOR_ADDRESS(331),
    SECTOR_332 = FLASH_SECTOR_ADDRESS(332),
    SECTOR_333 = FLASH_SECTOR_ADDRESS(333),
    SECTOR_334 = FLASH_SECTOR_ADDRESS(334),
    SECTOR_335 = FLASH_SECTOR_ADDRESS(335),
    SECTOR_336 = FLASH_SECTOR_ADDRESS(336),
    SECTOR_337 = FLASH_SECTOR_ADDRESS(337),
    SECTOR_338 = FLASH_SECTOR_ADDRESS(338),
    SECTOR_339 = FLASH_SECTOR_ADDRESS(339),
    SECTOR_340 = FLASH_SECTOR_ADDRESS(340),
    SECTOR_341 = FLASH_SECTOR_ADDRESS(341),
    SECTOR_342 = FLASH_SECTOR_ADDRESS(342),
    SECTOR_343 = FLASH_SECTOR_ADDRESS(343),
    SECTOR_344 = FLASH_SECTOR_ADDRESS(344),
    SECTOR_345 = FLASH_SECTOR_ADDRESS(345),
    SECTOR_346 = FLASH_SECTOR_ADDRESS(346),
    SECTOR_347 = FLASH_SECTOR_ADDRESS(347),
    SECTOR_348 = FLASH_SECTOR_ADDRESS(348),
    SECTOR_349 = FLASH_SECTOR_ADDRESS(349),
    SECTOR_350 = FLASH_SECTOR_ADDRESS(350),
    SECTOR_351 = FLASH_SECTOR_ADDRESS(351),
    SECTOR_352 = FLASH_SECTOR_ADDRESS(352),
    SECTOR_353 = FLASH_SECTOR_ADDRESS(353),
    SECTOR_354 = FLASH_SECTOR_ADDRESS(354),
    SECTOR_355 = FLASH_SECTOR_ADDRESS(355),
    SECTOR_356 = FLASH_SECTOR_ADDRESS(356),
    SECTOR_357 = FLASH_SECTOR_ADDRESS(357),
    SECTOR_358 = FLASH_SECTOR_ADDRESS(358),
    SECTOR_359 = FLASH_SECTOR_ADDRESS(359),
    SECTOR_360 = FLASH_SECTOR_ADDRESS(360),
    SECTOR_361 = FLASH_SECTOR_ADDRESS(361),
    SECTOR_362 = FLASH_SECTOR_ADDRESS(362),
    SECTOR_363 = FLASH_SECTOR_ADDRESS(363),
    SECTOR_364 = FLASH_SECTOR_ADDRESS(364),
    SECTOR_365 = FLASH_SECTOR_ADDRESS(365),
    SECTOR_366 = FLASH_SECTOR_ADDRESS(366),
    SECTOR_367 = FLASH_SECTOR_ADDRESS(367),
    SECTOR_368 = FLASH_SECTOR_ADDRESS(368),
    SECTOR_369 = FLASH_SECTOR_ADDRESS(369),
    SECTOR_370 = FLASH_SECTOR_ADDRESS(370),
    SECTOR_371 = FLASH_SECTOR_ADDRESS(371),
    SECTOR_372 = FLASH_SECTOR_ADDRESS(372),
    SECTOR_373 = FLASH_SECTOR_ADDRESS(373),
    SECTOR_374 = FLASH_SECTOR_ADDRESS(374),
    SECTOR_375 = FLASH_SECTOR_ADDRESS(375),
    SECTOR_376 = FLASH_SECTOR_ADDRESS(376),
    SECTOR_377 = FLASH_SECTOR_ADDRESS(377),
    SECTOR_378 = FLASH_SECTOR_ADDRESS(378),
    SECTOR_379 = FLASH_SECTOR_ADDRESS(379),
    SECTOR_380 = FLASH_SECTOR_ADDRESS(380),
    SECTOR_381 = FLASH_SECTOR_ADDRESS(381),
    SECTOR_382 = FLASH_SECTOR_ADDRESS(382),
    SECTOR_383 = FLASH_SECTOR_ADDRESS(383),
    SECTOR_384 = FLASH_SECTOR_ADDRESS(384),
    SECTOR_385 = FLASH_SECTOR_ADDRESS(385),
    SECTOR_386 = FLASH_SECTOR_ADDRESS(386),
    SECTOR_387 = FLASH_SECTOR_ADDRESS(387),
    SECTOR_388 = FLASH_SECTOR_ADDRESS(388),
    SECTOR_389 = FLASH_SECTOR_ADDRESS(389),
    SECTOR_390 = FLASH_SECTOR_ADDRESS(390),
    SECTOR_391 = FLASH_SECTOR_ADDRESS(391),
    SECTOR_392 = FLASH_SECTOR_ADDRESS(392),
    SECTOR_393 = FLASH_SECTOR_ADDRESS(393),
    SECTOR_394 = FLASH_SECTOR_ADDRESS(394),
    SECTOR_395 = FLASH_SECTOR_ADDRESS(395),
    SECTOR_396 = FLASH_SECTOR_ADDRESS(396),
    SECTOR_397 = FLASH_SECTOR_ADDRESS(397),
    SECTOR_398 = FLASH_SECTOR_ADDRESS(398),
    SECTOR_399 = FLASH_SECTOR_ADDRESS(399),
    SECTOR_400 = FLASH_SECTOR_ADDRESS(400),
    SECTOR_401 = FLASH_SECTOR_ADDRESS(401),
    SECTOR_402 = FLASH_SECTOR_ADDRESS(402),
    SECTOR_403 = FLASH_SECTOR_ADDRESS(403),
    SECTOR_404 = FLASH_SECTOR_ADDRESS(404),
    SECTOR_405 = FLASH_SECTOR_ADDRESS(405),
    SECTOR_406 = FLASH_SECTOR_ADDRESS(406),
    SECTOR_407 = FLASH_SECTOR_ADDRESS(407),
    SECTOR_408 = FLASH_SECTOR_ADDRESS(408),
    SECTOR_409 = FLASH_SECTOR_ADDRESS(409),
    SECTOR_410 = FLASH_SECTOR_ADDRESS(410),
    SECTOR_411 = FLASH_SECTOR_ADDRESS(411),
    SECTOR_412 = FLASH_SECTOR_ADDRESS(412),
    SECTOR_413 = FLASH_SECTOR_ADDRESS(413),
    SECTOR_414 = FLASH_SECTOR_ADDRESS(414),
    SECTOR_415 = FLASH_SECTOR_ADDRESS(415),
    SECTOR_416 = FLASH_SECTOR_ADDRESS(416),
    SECTOR_417 = FLASH_SECTOR_ADDRESS(417),
    SECTOR_418 = FLASH_SECTOR_ADDRESS(418),
    SECTOR_419 = FLASH_SECTOR_ADDRESS(419),
    SECTOR_420 = FLASH_SECTOR_ADDRESS(420),
    SECTOR_421 = FLASH_SECTOR_ADDRESS(421),
    SECTOR_422 = FLASH_SECTOR_ADDRESS(422),
    SECTOR_423 = FLASH_SECTOR_ADDRESS(423),
    SECTOR_424 = FLASH_SECTOR_ADDRESS(424),
    SECTOR_425 = FLASH_SECTOR_ADDRESS(425),
    SECTOR_426 = FLASH_SECTOR_ADDRESS(426),
    SECTOR_427 = FLASH_SECTOR_ADDRESS(427),
    SECTOR_428 = FLASH_SECTOR_ADDRESS(428),
    SECTOR_429 = FLASH_SECTOR_ADDRESS(429),
    SECTOR_430 = FLASH_SECTOR_ADDRESS(430),
    SECTOR_431 = FLASH_SECTOR_ADDRESS(431),
    SECTOR_432 = FLASH_SECTOR_ADDRESS(432),
    SECTOR_433 = FLASH_SECTOR_ADDRESS(433),
    SECTOR_434 = FLASH_SECTOR_ADDRESS(434),
    SECTOR_435 = FLASH_SECTOR_ADDRESS(435),
    SECTOR_436 = FLASH_SECTOR_ADDRESS(436),
    SECTOR_437 = FLASH_SECTOR_ADDRESS(437),
    SECTOR_438 = FLASH_SECTOR_ADDRESS(438),
    SECTOR_439 = FLASH_SECTOR_ADDRESS(439),
    SECTOR_440 = FLASH_SECTOR_ADDRESS(440),
    SECTOR_441 = FLASH_SECTOR_ADDRESS(441),
    SECTOR_442 = FLASH_SECTOR_ADDRESS(442),
    SECTOR_443 = FLASH_SECTOR_ADDRESS(443),
    SECTOR_444 = FLASH_SECTOR_ADDRESS(444),
    SECTOR_445 = FLASH_SECTOR_ADDRESS(445),
    SECTOR_446 = FLASH_SECTOR_ADDRESS(446),
    SECTOR_447 = FLASH_SECTOR_ADDRESS(447),
    SECTOR_448 = FLASH_SECTOR_ADDRESS(448),
    SECTOR_449 = FLASH_SECTOR_ADDRESS(449),
    SECTOR_450 = FLASH_SECTOR_ADDRESS(450),
    SECTOR_451 = FLASH_SECTOR_ADDRESS(451),
    SECTOR_452 = FLASH_SECTOR_ADDRESS(452),
    SECTOR_453 = FLASH_SECTOR_ADDRESS(453),
    SECTOR_454 = FLASH_SECTOR_ADDRESS(454),
    SECTOR_455 = FLASH_SECTOR_ADDRESS(455),
    SECTOR_456 = FLASH_SECTOR_ADDRESS(456),
    SECTOR_457 = FLASH_SECTOR_ADDRESS(457),
    SECTOR_458 = FLASH_SECTOR_ADDRESS(458),
    SECTOR_459 = FLASH_SECTOR_ADDRESS(459),
    SECTOR_460 = FLASH_SECTOR_ADDRESS(460),
    SECTOR_461 = FLASH_SECTOR_ADDRESS(461),
    SECTOR_462 = FLASH_SECTOR_ADDRESS(462),
    SECTOR_463 = FLASH_SECTOR_ADDRESS(463),
    SECTOR_464 = FLASH_SECTOR_ADDRESS(464),
    SECTOR_465 = FLASH_SECTOR_ADDRESS(465),
    SECTOR_466 = FLASH_SECTOR_ADDRESS(466),
    SECTOR_467 = FLASH_SECTOR_ADDRESS(467),
    SECTOR_468 = FLASH_SECTOR_ADDRESS(468),
    SECTOR_469 = FLASH_SECTOR_ADDRESS(469),
    SECTOR_470 = FLASH_SECTOR_ADDRESS(470),
    SECTOR_471 = FLASH_SECTOR_ADDRESS(471),
    SECTOR_472 = FLASH_SECTOR_ADDRESS(472),
    SECTOR_473 = FLASH_SECTOR_ADDRESS(473),
    SECTOR_474 = FLASH_SECTOR_ADDRESS(474),
    SECTOR_475 = FLASH_SECTOR_ADDRESS(475),
    SECTOR_476 = FLASH_SECTOR_ADDRESS(476),
    SECTOR_477 = FLASH_SECTOR_ADDRESS(477),
    SECTOR_478 = FLASH_SECTOR_ADDRESS(478),
    SECTOR_479 = FLASH_SECTOR_ADDRESS(479),
    SECTOR_480 = FLASH_SECTOR_ADDRESS(480),
    SECTOR_481 = FLASH_SECTOR_ADDRESS(481),
    SECTOR_482 = FLASH_SECTOR_ADDRESS(482),
    SECTOR_483 = FLASH_SECTOR_ADDRESS(483),
    SECTOR_484 = FLASH_SECTOR_ADDRESS(484),
    SECTOR_485 = FLASH_SECTOR_ADDRESS(485),
    SECTOR_486 = FLASH_SECTOR_ADDRESS(486),
    SECTOR_487 = FLASH_SECTOR_ADDRESS(487),
    SECTOR_488 = FLASH_SECTOR_ADDRESS(488),
    SECTOR_489 = FLASH_SECTOR_ADDRESS(489),
    SECTOR_490 = FLASH_SECTOR_ADDRESS(490),
    SECTOR_491 = FLASH_SECTOR_ADDRESS(491),
    SECTOR_492 = FLASH_SECTOR_ADDRESS(492),
    SECTOR_493 = FLASH_SECTOR_ADDRESS(493),
    SECTOR_494 = FLASH_SECTOR_ADDRESS(494),
    SECTOR_495 = FLASH_SECTOR_ADDRESS(495),
    SECTOR_496 = FLASH_SECTOR_ADDRESS(496),
    SECTOR_497 = FLASH_SECTOR_ADDRESS(497),
    SECTOR_498 = FLASH_SECTOR_ADDRESS(498),
    SECTOR_499 = FLASH_SECTOR_ADDRESS(499),
    SECTOR_500 = FLASH_SECTOR_ADDRESS(500),
    SECTOR_501 = FLASH_SECTOR_ADDRESS(501),
    SECTOR_502 = FLASH_SECTOR_ADDRESS(502),
    SECTOR_503 = FLASH_SECTOR_ADDRESS(503),
    SECTOR_504 = FLASH_SECTOR_ADDRESS(504),
    SECTOR_505 = FLASH_SECTOR_ADDRESS(505),
    SECTOR_506 = FLASH_SECTOR_ADDRESS(506),
    SECTOR_507 = FLASH_SECTOR_ADDRESS(507),
    SECTOR_508 = FLASH_SECTOR_ADDRESS(508),
    SECTOR_509 = FLASH_SECTOR_ADDRESS(509),
    SECTOR_510 = FLASH_SECTOR_ADDRESS(510),
    SECTOR_511 = FLASH_SECTOR_ADDRESS(511)
};

enum class Flash_Page {
    PAGE_0 = FLASH_PAGE_ADDRESS(0),
    PAGE_1 = FLASH_PAGE_ADDRESS(1),
    PAGE_2 = FLASH_PAGE_ADDRESS(2),
    PAGE_3 = FLASH_PAGE_ADDRESS(3),
    PAGE_4 = FLASH_PAGE_ADDRESS(4),
    PAGE_5 = FLASH_PAGE_ADDRESS(5),
    PAGE_6 = FLASH_PAGE_ADDRESS(6),
    PAGE_7 = FLASH_PAGE_ADDRESS(7),
    PAGE_8 = FLASH_PAGE_ADDRESS(8),
    PAGE_9 = FLASH_PAGE_ADDRESS(9),
    PAGE_10 = FLASH_PAGE_ADDRESS(10),
    PAGE_11 = FLASH_PAGE_ADDRESS(11),
    PAGE_12 = FLASH_PAGE_ADDRESS(12),
    PAGE_13 = FLASH_PAGE_ADDRESS(13),
    PAGE_14 = FLASH_PAGE_ADDRESS(14),
    PAGE_15 = FLASH_PAGE_ADDRESS(15),
};

#endif