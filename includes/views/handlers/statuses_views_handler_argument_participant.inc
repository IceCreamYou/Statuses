<?php

/**
 * @file
 *   Allow only statuses where a given user is a participant.
 */

/**
 * Argument handler to select statuses where a given user is a participant.
 */
class statuses_views_handler_argument_participant extends views_handler_argument {
  function query($group_by = FALSE) {
    $argument = $this->argument;
    $this->query->add_where(0, db_or()
        ->condition("sender", $argument)
        ->condition(db_and()
          ->condition("recipient", $argument)
          ->condition("type", 'user')));
  }
}
