module Main where

import qualified Data.ByteString.Lazy as BL
import qualified Data.Foldable as F
-- cassava
import Data.Csv.Streaming

type Stats = (BL.ByteString, Int, BL.ByteString, Int)

fourth :: (a, b, c, d) -> d
fourth (_, _, _, d) = d

stats :: BL.ByteString -> Records Stats
stats = decode NoHeader

main :: IO()
main = do
  csvData <- BL.readFile "../data/sample.csv"
  let summed = F.foldr summer 0 (stats csvData)
  putStrLn $ show (summed)
  where summer = (+) . fourth
