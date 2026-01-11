#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QString>
#include <QMap>

class ScoreManager
{
public:
    ScoreManager();

    void addWin(const QString& playerName);
    void saveToFile();
    void loadFromFile();
    QMap<QString, int> getScores();

private:
    QMap<QString, int> scores;  // playerName -> wins
    QString filename;
};

#endif // SCOREMANAGER_H
