module Main where

import Text.XML.HXT.Core
import Data.Map (Map, fromList, toList)

class XmlPickler a where
  xpickle :: PU a

instance XmlPickler Season where
  xpickle = xpPersons

instance XmlPickler Season where
  xpickle = xpPerson

data Persons = Persons
  {
    persons :: [Person]
  }
  deriving (Show, Eq)

data Person = Person
  {
    name :: String
  , age :: Int
  }
  deriving (Show, Eq)

xpPersons :: PU Persons
xpPersons
 =  xpElem "data" $
    xpWrap ( fromList
          , toList
          ) $
    xpList $
    xpElem [] xpickle

xpPerson :: PU Person
xpPerson
  = xpElem "person" $
    xpWrap ( \ ((n,a)) -> Player n a
            , \ t -> (name n, age a)
          ) $
      xp2Tuple  (xpAttr "name" xpText)
                (xpAttr "age" xpText)

main :: IO()
main = do
  runX ( xunpickleDocument xpSeason
                                [ withValidate no
                                , withTrace 1
                                , withRemoveWS yes
                                , withPreserveComment no
                                ] "../data/sample.xml"
      )
  >>>
  processPersons
  >>>

processPersons :: IOSArrow Persons Persons
processPersons
  = arrIO ( \ x -> do { print x ; return x })
