#include "scoremanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ScoreManager::ScoreManager()
{
    filename = "scores.txt";
    loadFromFile();
}

void ScoreManager::addWin(const QString& playerName)
{
    if (playerName.isEmpty() || playerName == "Draw") {
        return;  // Don't record draws
    }

    // Increment player's score
    if (scores.contains(playerName)) {
        scores[playerName]++;
    } else {
        scores[playerName] = 1;
    }

    saveToFile();
}

void ScoreManager::saveToFile()
{
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error saving scores";
        return;
    }

    QTextStream out(&file);

    // Write each player and their score
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        out << it.key() << ":" << it.value() << "\n";
    }

    file.close();
}

void ScoreManager::loadFromFile()
{
    QFile file(filename);

    if (!file.exists()) {
        return;  // No file yet
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error loading scores";
        return;
    }

    QTextStream in(&file);
    scores.clear();

    // Read line by line
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");

        if (parts.size() == 2) {
            QString name = parts[0];
            int wins = parts[1].toInt();
            scores[name] = wins;
        }
    }

    file.close();
}

QMap<QString, int> ScoreManager::getScores()
{
    return scores;
}
