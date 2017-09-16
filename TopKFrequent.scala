object Solution extends App{
  def topKFrequent(nums: Array[Int], k: Int): List[Int] = {
    val tmpMap: collection.mutable.Map[Int, Int]
    nums.foreach { n =>
      tmpMap.put(n, tmpMap.getOrElse(n, 0)+1)
    }

    tmpMap.toList.sorted(_._2).take(k).map(_._1).toList
  }

  val ll = List[1,1,1,2,2,3]

  println(ll, 2)
}