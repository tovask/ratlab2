% TODO: 3.1
% Végezzük el a mérést a második fájlra (meres2.mat)
% A névleges távolságok alapján számoljunk távolság mérési hibát!
% Külön master és slave egységre!
load("meres2.mat");
[DM, DS, PX, PY] = CalculatePosition(Measurement);
% névleges távolságok:
D = 1.4; % master és slave távolsága
nominal_master_distance = sqrt( (D-NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
nominal_slave_distance = sqrt( (NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
% a távolság mérés hibája:
distance_error_M = DM - nominal_master_distance;
distance_error_S = DS - nominal_slave_distance;

% TODO: 3.2
% A távolság hibákból számoljuk idõmérési hibát
% Figyeljünk rá, hogy minden méréshez külön hõmérséklet tartozik!
% terjedési sebesség:
c = 331.3 * sqrt(1 + [Measurement.Temperature] / 273.15);
% korrekciós időtag:
time_error_M = distance_error_M ./ c;
time_error_S = distance_error_S ./ c;


% TODO: 3.3
% Jelenítsük meg a konzolban (disp) a master és slave idõmérési hibák
% átlagát.
disp("master idõmérési hibája: "+mean(time_error_M)+"s");
disp("slave idõmérési hibája: "+mean(time_error_S)+"s");


% TODO: 3.4
% Módosítsuk a CalculatePosition függvényt az új korrekciós tényezõkkel
% Vizsgáljuk meg újra a méréseket (Számoljuk ki újra a korrekciós idõket,
% majd ábrázoljuk õket újra!)
% Vessük össze a második feladattal!
plotManualMeas
