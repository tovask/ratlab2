% Ábraablakok tartalmának törlése (előző futtatások)
figure(1);clf;
figure(2);clf;

D = 1.4; % master és slave távolsága

% TODO: 1.6
% Töltsük be az egyik mérést (meresN.mat) és hívjuk meg a CalculatePosition
% függvényt
load("meres1.mat");
[DM, DS, PX, PY] = CalculatePosition(Measurement);

% TODO: 2.2
% Ábrázoljuk a méréseket két külön ábrában
% Az egyik ábrán a számolt távolságok legyenek kijelezve
% A másikon a koordináták
% Mindkét ábrán a mérések legyenek piros X-el jelölve
% Ábrázoljuk a mérések átlagát kék + jellel
% Ábrázoljuk a névleges értékeket (NominalPos struktúra) zöld körrel
figure(1) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(DM, DS,'rx') % számított távolságok
plot(mean(DM), mean(DS),'b+') % átlag

% névleges távolságok:
nominal_master_distance = sqrt( (D-NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
nominal_slave_distance = sqrt( (NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
plot(nominal_master_distance, nominal_slave_distance,'go')

figure(2) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(PX,PY,'rx') % számított pozíciók
plot(mean(PX),mean(PY),'b+') % pozíciók átlaga
plot(NominalPos.X/100,NominalPos.Y/100,'go') % névleges pozíció

% TODO: 2.3
% Töltsük be a többi fájlt és ábrázoljuk azokat is
% Ugyan ebben a két ábrában dolgozzunk! (Három elkülönülõ pontfehõt fogunk
% látni)

% ezt lehetne egy ciklussal is...

load("meres2.mat");
[DM, DS, PX, PY] = CalculatePosition(Measurement);
figure(1) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(DM, DS,'rx') % számított távolságok
plot(mean(DM), mean(DS),'b+') % átlag

% névleges távolságok:
nominal_master_distance = sqrt( (D-NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
nominal_slave_distance = sqrt( (NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
plot(nominal_master_distance, nominal_slave_distance,'go')

figure(2) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(PX,PY,'rx') % számított pozíciók
plot(mean(PX),mean(PY),'b+') % pozíciók átlaga
plot(NominalPos.X/100,NominalPos.Y/100,'go') % névleges pozíció



load("meres3.mat");
[DM, DS, PX, PY] = CalculatePosition(Measurement);
figure(1) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(DM, DS,'rx') % számított távolságok
plot(mean(DM), mean(DS),'b+') % átlag

% névleges távolságok:
nominal_master_distance = sqrt( (D-NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
nominal_slave_distance = sqrt( (NominalPos.X/100)^2 + (NominalPos.Y/100)^2);
plot(nominal_master_distance, nominal_slave_distance,'go')

figure(2) % új ábra ablak megnyitása
hold on % egymásra rajzolás engedélyezése ebben az ábrában
plot(PX,PY,'rx') % számított pozíciók
plot(mean(PX),mean(PY),'b+') % pozíciók átlaga
plot(NominalPos.X/100,NominalPos.Y/100,'go') % névleges pozíció
