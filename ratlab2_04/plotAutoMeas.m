% TODO: 4.1
% Nyissuk meg a kalibrált méréseket tartalmazó fájlokat (autoN.mat)
% Ábrázoljuk a méréseket és azok átlagát a 2. feladatban használt módon
% Külön ábrába a távolságokat és a koordinátákat!
figure(1);clf; % ábra tisztítása
figure(2);clf; % ábra tisztítása
D = 140; % master és slave távolsága (cm)
for N = 1 : 9
    % mérés megnyitása (adatok centiméterben vannak benne!!!)
    load("auto"+N+".mat")
    
    figure(1) % távolságok ábra ablak megnyitása
    hold on % egymásra rajzolás engedélyezése ebben az ábrában
    plot(DM, DS,'rx') % számított távolságok
    plot(mean(DM), mean(DS),'b+') % átlag
    
    % névleges távolságok:
    nominal_master_distance = sqrt( (D-NominalPos.X)^2 + (NominalPos.Y)^2);
    nominal_slave_distance = sqrt( (NominalPos.X)^2 + (NominalPos.Y)^2);
    plot(nominal_master_distance, nominal_slave_distance,'go')
    
    figure(2) % pozíciók ábra ablak megnyitása
    hold on % egymásra rajzolás engedélyezése ebben az ábrában
    plot(PX,PY,'rx') % számított pozíciók
    plot(mean(PX),mean(PY),'b+') % pozíciók átlaga
    plot(NominalPos.X,NominalPos.Y,'go') % névleges pozíció


% TODO: 4.2
% Számítsuk ki a mérések kovariancia mátrixát!
% Ábrázoljunk a hiba ellipsziseket (ErrorEllipse függvény) 99%-os
% konfidencia intervallummal!
    figure(1) % távolságok ábra ablak megnyitása
    Cxy = cov(DM,DS); % kovariancia mátrix
    Mxy = [mean(DM), mean(DS)]; % átlag értékek
    ErrorEllipse(Cxy, Mxy, 'conf', 0.99)
    
    figure(2) % pozíciók ábra ablak megnyitása
    Cxy = cov(PX,PY); % kovariancia mátrix
    Mxy = [mean(PX), mean(PY)]; % átlag értékek
    ErrorEllipse(Cxy, Mxy, 'conf', 0.99)

end % egy mérés kirajzolásának vége

% TODO: 4.3
% Vizsgáljuk meg az ellipszisek állását a távolságok ábráján! Mire lehet
% ebbõl következtetni?
% Vizsgáljuk meg ugyan ezt a koordináták esetén, mit tapasztalunk?
% Vessük össze a közeli és távoli méréseket, mit lenne az elvárt, mégis mit
% tapasztalunk?


